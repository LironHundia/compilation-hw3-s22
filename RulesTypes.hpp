#ifndef _RULES_TYPES_
#define _RULES_TYPES_

#include <iostream>
#include <vector>

class BaseClass {
public:
    BaseClass();
    virtual ~BaseClass();
    virtual std::string getType() {std::cout << "error with getType()!" << std::endl;}
    virtual std::string getId() {std::cout << "error with getId()!" << std::endl;}
    virtual std::vector<std::string> getVecArgsType() {std::cout << "error with getVecArgsType()!" << std::endl;}
    virtual std::vector<std::string> getVecArgsID() {std::cout << "error with getVecArgsID()!" << std::endl;}
    virtual void addNewArg(std::string argType, std::string argID) {std::cout << "error with addNewArg()!" << std::endl;}
    virtual std::string getArgType() {std::cout << "error with getArgType()!" << std::endl;}
    virtual std::string getArgID() {std::cout << "error with getArgID()!" << std::endl;}
    virtual std::string getValue() {std::cout << "error with getValue()!" << std::endl;}
};

class RetTypeClass : public BaseClass {
private:
    std::string type;
public:
    RetTypeClass(std::string type);
    ~RetTypeClass() override;
    std::string getType();
};

class TypeClass : public BaseClass {
private:
    std::string type;
public:
    TypeClass(std::string type);
    ~TypeClass() override;
    std::string getType();
};

class IDClass : public BaseClass {
private:
    std::string id;
public:
    IDClass(std::string id);
    ~IDClass() override;
    std::string getId();
};

class FormalsClass : public BaseClass {
private:
    std::vector<std::string> vecArgsType;
    std::vector<std::string> vecArgsID;
public:
    FormalsClass(std::vector<std::string> argsType = std::vector<std::string>(),
                 std::vector<std::string> argsID = std::vector<std::string>()););
    ~FormalsClass() override;
    std::vector<std::string> getVecArgsType();
    std::vector<std::string> getVecArgsID();
};

class FormalsListClass : public BaseClass {
private:
    std::vector<std::string> vecArgsType;
    std::vector<std::string> vecArgsID;
public:
    FormalsListClass(std::vector<std::string> argsType = std::vector<std::string>(),
                     std::vector<std::string> argsID = std::vector<std::string>());
    ~FormalsListClass() override;
    std::vector<std::string> getVecArgsType();
    std::vector<std::string> getVecArgsID();
    void addNewArg(std::string argType, std::string argID);
};

class FormalDeclClass : public BaseClass {
private:
    std::string argType;
    std::string argID;
public:
    FormalDeclClass(std::string type, std::string id);
    ~FormalDeclClass() override;
    std::string getArgType();
    std::string getArgID();
};

class ExpClass : public BaseClass {
private:
    std::string type;
    std::string value;
public:
    ExpClass(std::string type, std::string value = std::string());
    ~ExpClass() override;
    std::string getType();
    std::string getValue();
};

class NUMClass : public BaseClass {
private:
    std::string value;
public:
    IDClass(std::string value);
    ~IDClass() override;
    std::string getValue();
};







#endif //_RULES_TYPES_
