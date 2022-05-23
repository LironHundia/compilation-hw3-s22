#include "RulesTypes.hpp"
#include <string>

RetTypeClass::RetTypeClass(std::string type) : type(type) {}
std::string RetTypeClass::getType() {return type;}

TypeClass::TypeClass(std::string type) : type(type) {}
std::string TypeClass::getType() {return type;}

IDClass::IDClass(std::string id) : id(id) {}
std::string IDClass::getId() {return id;}


FormalsClass::FormalsClass(std::vector<std::string> argsType, std::vector<std::string> argsID) : vecArgsType(argsType), vecArgsID(argsID) {}
std::vector<std::string> FormalsClass::getVecArgsType() {return vecArgsType;}
std::vector<std::string> FormalsClass::getVecArgsID() {return vecArgsID;}


FormalsListClass::FormalsListClass(std::vector<std::string> argsType, std::vector<std::string> argsID) : vecArgsType(argsType), vecArgsID(argsID) {}
std::vector<std::string> FormalsListClass::getVecArgsType() {return vecArgsType;}
std::vector<std::string> FormalsListClass::getVecArgsID() {return vecArgsID;}
void FormalsListClass::addNewArg(std::string argType, std::string argID)
{
    vecArgsType.push_back(argType);
    vecArgsID.push_back(argID);
}

FormalDeclClass::FormalDeclClass(std::string type, std::string id) : argType(type), argID(id) {}
std::string FormalDeclClass::getArgType() {
    return argType;
}
std::string FormalDeclClass::getArgID() {
    return argID;
}


ExpClass::ExpClass(std::string type, std::string value) : type(type), value(value) {}
std::string ExpClass::getType() {
    return type;
}
std::string ExpClass::getValue() {
    return value;
}


NUMClass::NUMClass(std::string value) : value(value) {}
std::string NUMClass::getValue() {
    return value;
}
