#ifndef _UTILITIES_
#define _UTILITIES_

#include <iostream>

void checkIfBValid(std::string value);
void checkIfBool(std::string type);
void checkIfNumeric(std::string type);
std::string setRetBinopType(std::string typeLeft, std::string typeRight);
std::string getIdType(std::string id);
void addVarNewEntry(std::string id, std::string type);
void addFuncNewEntry(std::string id, std::string type, std::vector<std::string> vecArgsType = std::vector<std::string>());
void addFuncArgsToTable(std::vector<std::string> vecArgsType, std::vector<std::string> vecArgsId);
void checkValidArgs(std::vector<std::string>& vecArgsId);
void openScope();
void closeScope();
#endif //_UTILITIES_
