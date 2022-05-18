#include "RulesTypes.hpp"

RetTypeClass::RetTypeClass(std::string type) : type(type) {}
std::string RetTypeClass::getType() {return type;}

TypeClass::TypeClass(std::string type) : type(type) {}
std::string TypeClass::getType() {return type;}

IDClass::IDClass(std::string id) : id(id) {}
std::string IDClass::getId() {return id;}


FormalsClass::FormalsClass(std::vector<std::string> argsType = std::vector<std::string>(),
                           std::vector<std::string> argsID = std::vector<std::string>()) : vecArgsType(argsType), vecArgsID(argsID) {}
//FormalsClass::~FormalsClass() = default;
std::vector<std::string> FormalsClass::getArgsType() {return vecArgsType;}
std::vector<std::string> FormalsClass::getArgsID() {return vecArgsID;}


FormalsListClass::FormalsListClass(std::vector<std::string> argsType = std::vector<std::string>(),
                           std::vector<std::string> argsID = std::vector<std::string>()) : vecArgsType(argsType), vecArgsID(argsID) {}
//FormalsListClass::~FormalsListClass() = default;
std::vector<std::string> FormalsListClass::getArgsType() {return vecArgsType;}
std::vector<std::string> FormalsListClass::getArgsID() {return vecArgsID;}
void FormalsListClass::addNewArg(std::string argType, std::string argID)
{
    vecArgsType.pushback(argType);
    vecArgsID.pushback(argID);
}

FormalDeclClass::FormalDeclClass(std::string type, std::string id) : argType(type), argID(id) {}
FormalDeclClass::~FormalDeclClass() = default;
std::string FormalDeclClass::getArgType() {return argType;}
std::string FormalDeclClass::getArgID() {return argID;}





#endif //_RULES_TYPES_
