#ifndef _UTILITIES_
#define _UTILITIES_

#include <iostream>

void checkIfBValid(std::string value);
void checkIfBool(std::string type);
void checkIfNumeric(std::string type);
std::string setRetBinopType(std::string typeLeft, std::string typeRight);
std::string getIdType(std::string id);
void addNewEntry(std::string id, std::string type, bool isFunc = false, std::vector<std::string> argsTypes = std::vector<std::string>());
#endif //_UTILITIES_
