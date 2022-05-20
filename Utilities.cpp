#include "Utilities.hpp"
#include "hw3_output.hpp"

SymbolTable symbolTable;

void checkIfBValid(std::string value) {
    try {
        int byteValue = std::stoi(value);
        if (byteValue > 255) {
            output::errorByteTooLarge(yylineno, value);
            exit(0);
        }
    }
    catch (...) {
        sdt::cout << "recieved exception in checkIfBValid!" << std::endl;
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

void addNewEntry(std::string id, std::string type, bool isFunc, std::vector<std::string> argsTypes) {
    TableEntry* entryOfId = symbolTable.findEntryInTable(id);

    if (entryOfId != nullptr) {
        output::errorDef(yylineno,id);
        exit(0);
    }
    TableScope topScope = symbolTable.getTopScope();
    if (isFunc) {
        TableEntry newEntry(id, 0, type, isFunc, argsTypes);
    }
    else {
        TableEntry newEntry(id, symbolTable.getOffset(), type, isFunc, argsTypes);
        symbolTable.incOffset();
    }
    topScope.pushEntry(newEntry);
}









//test
