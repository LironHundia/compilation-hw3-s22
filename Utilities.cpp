#include "Utilities.hpp"
#include "hw3_output.hpp"
#include <algorithm>

SymbolTable symbolTable;
int WhileCounter = 0;
static TableEntry& getCurrFunc();


void checkIfBValid(std::string value) {
    try {
        int byteValue = std::stoi(value);
        if (byteValue > 255) {
            output::errorByteTooLarge(yylineno, value);
            exit(0);
        }
    }
    catch (...) {
        std::cout << "recieved exception in checkIfBValid!" << std::endl;
        exit(1);
    }
    return;
}

void checkIfBool(std::string type) {
    if (type != "BOOL") {
        output::errorMismatch(yylineno);
        exit(0);
    }
}

void checkIfNumeric(std::string type) {
    if ((type != "INT") && (type != "BYTE")) {
        output::errorMismatch(yylineno);
        exit(0);
    }
}

void checkIfAssignValidByType(std::string dstType, std::string srcType){
	if(dstType != srcType){
		if ((dstType != "INT") && (srcType == "BYTE")) {
			output::errorMismatch(yylineno);
			exit(0);
		}
	}
}

void checkIfBreakValid(){
	if(WhileCounter == 0){
		output::errorUnexpectedBreak(yylineno);
		exit(0);
	}

}
void checkIfContinueValid(){
	if(WhileCounter == 0){
		output::errorUnexpectedContinue(yylineno);
		exit(0);
	}
}

std::string setRetBinopType(std::string typeLeft, std::string typeRight) {
    checkIfNumeric(typeLeft);
    checkIfNumeric(typeRight);
    if ((typeLeft == "INT") || (typeRight != "INT")) {
        return "INT";
    }
    return "BYTE";
}

std::string getIdType(std::string id) {
    TableEntry* entryOfId = symbolTable.findEntryInTable(id);
    if (entryOfId == nullptr) {
        output::errorUndef(yylineno, id);
        exit(0);
    }
    return entryOfId->getType();
}

//adding variable to symbolTable
void addVarNewEntry(std::string id, std::string type) {
    TableEntry* entryOfId = symbolTable.findEntryInTable(id); //check its not already exist
    if (entryOfId != nullptr) {
        output::errorDef(yylineno,id);
        exit(0);
    }
	TableScope& topScope = symbolTable.getTopScope();
	topScope.pushEntry(id, symbolTable.getOffset(), type);
	symbolTable.incOffset();
}

//adding function to symbolTable
void addFuncNewEntry(std::string id, std::string retType, std::vector<std::string> vecArgsType) {
    TableEntry* entryOfId = symbolTable.findEntryInTable(id);
    if (entryOfId == nullptr) {
        output::errorUndef(yylineno, id);
        exit(0);
    }
    //need to change the diractions of the args in the vector.
    std::reverse(vecArgsType.begin(), vecArgsType.end());
    /*for (std::vector<std::string>::reverse_iterator it = vecArgsType.rbegin(); it != vecArgsType.rend(); ++it) {
        reverseArgs.push_back(*it);
    }*/
    //push final result to table
    TableScope& topScope = symbolTable.getTopScope();
    topScope.pushEntry(id, 0, retType, true, vecArgsType);
}

//adding functions arguments to the new function scope
void addFuncArgsToTable(std::vector<std::string> vecArgsType, std::vector<std::string> vecArgsId) {
    //should be the same size
    checkValidArgs(vecArgsId); //see description above the function implementation
    if (!vecArgsType.empty()){ //case there is at least 1 argument
       TableScope& topScope = symbolTable.getTopScope();
       int argOffset = -1; //ensures that their indexes are negative order.
       for (size_t i = (vecArgsType.size() - 1); i >= 0; i--) { //need to switch the order.
          topScope.pushEntry(vecArgsId[i], argOffset, vecArgsType[i]);
          argOffset--;
          if (i == 0){
              break;
          }
       }
    }
}

//helper function - check that there are not same ID in func declaration / in table already
void checkValidArgs(std::vector<std::string>& vecArgsId) {
    //check there is not same id in signature
	for (size_t i = 0; i < vecArgsId.size(); i++) {
		for (size_t j = i + 1; j < vecArgsId.size(); j++) {
			if (vecArgsId[i] == vecArgsId[j]) {
				output::errorDef(yylineno, vecArgsId[i]);
				exit(0);
			}
		}
	}
    //check there is not same id in symbolTable
	for (std::vector<std::string>::iterator it = vecArgsId.begin(); it != vecArgsId.end(); ++it) {
		if (symbolTable.findEntryInTable(*it) != nullptr) {
			output::errorDef(yylineno, *it);
			exit(0);
		}
	}
}

static TableEntry& getCurrFunc(){
	TableEntry& currFuncEntry = symbolTable.getFirstScope().topEntry();
}

void checkReturnType(std::string type){
	checkIfAssignValidByType(getCurrFunc().getType(), type);
}

void openScope() {
  symbolTable.pushScope();
}

void closeScope() {
  output::endScope();
  //need to print the scope's content
  symbolTable.popScope();
}

void incWhileCounter() {
    WhileCounter++;
}
void decWhileCounter() {
    WhileCounter--;
}

std::string checkFuncCall(std::string funcId, std::vector<std::string> vecArgsTypes) {
    TableEntry* funcEntry = symbolTable.getFirstScope().findEntryInScope(funcId); //checking specifically in the "func scope"
    if (funcEntry == nullptr || funcEntry->getIsFunc() == false) {
        output::errorUndefFunc(yylineno, funcId);
        exit(0);
    }
    std::vector<std::string> vecFuncTypes = funcEntry->getVecArgsTypes(); //already reversed!!!
    std::reverse(vecArgsTypes.begin(), vecArgsTypes.end());

    if (vecFuncTypes.size() != vecArgsTypes.size()) {
        output::errorPrototypeMismatch(yylineno, funcId, vecFuncTypes);
    }

    for (int i = 0; i < vecFuncTypes.size(); i++) {
        if(vecFuncTypes[i] != vecArgsTypes[i]) {
            output::errorPrototypeMismatch(yylineno, funcId, vecFuncTypes);
        }
    }
    return funcEntry->getType();
}


//test
