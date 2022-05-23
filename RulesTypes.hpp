#ifndef _RULES_TYPES_
#define _RULES_TYPES_

#include <iostream>
#include <vector>
#include <string>

class BaseClass {
public:
    virtual ~BaseClass() = default;
    virtual std::string getType() {std::cout << "error with getType()!" << std::endl;}
    virtual std::string getId() {std::cout << "error with getId()!" << std::endl;}
    virtual std::vector<std::string> getVecArgsType() {std::cout << "error with getVecArgsType()!" << std::endl;}
    virtual std::vector<std::string> getVecArgsID() {std::cout << "error with getVecArgsID()!" << std::endl;}
    virtual void addNewArg(std::string argType, std::string argID) {std::cout << "error with addNewArg()!" << std::endl;}
    virtual std::string getArgType() {std::cout << "error with getArgType()!" << std::endl;}
    virtual std::string getArgID() {std::cout << "error with getArgID()!" << std::endl;}
    virtual std::string getValue() {std::cout << "error with getValue()!" << std::endl;}
    virtual void addNewArgType(std::string argType) {std::cout << "error with addNewArgType()!" << std::endl;}
};

class RetTypeClass : public BaseClass {
private:
    std::string type;
public:
    RetTypeClass(std::string type);
    ~RetTypeClass() = default;
    std::string getType() override;
};

class TypeClass : public BaseClass {
private:
    std::string type;
public:
    TypeClass(std::string type);
    ~TypeClass() = default;
    std::string getType() override;
};

class IDClass : public BaseClass {
private:
    std::string id;
public:
    IDClass(std::string id);
    ~IDClass() = default;
    std::string getId() override;
};

class FormalsClass : public BaseClass {
private:
    std::vector<std::string> vecArgsType;
    std::vector<std::string> vecArgsID;
public:
    FormalsClass(std::vector<std::string> argsType = std::vector<std::string>(),
                 std::vector<std::string> argsID = std::vector<std::string>());
    ~FormalsClass() = default;
    std::vector<std::string> getVecArgsType() override;
    std::vector<std::string> getVecArgsID() override;
};

class FormalsListClass : public BaseClass {
private:
    std::vector<std::string> vecArgsType;
    std::vector<std::string> vecArgsID;
public:
    FormalsListClass(std::vector<std::string> argsType = std::vector<std::string>(),
                     std::vector<std::string> argsID = std::vector<std::string>());
    ~FormalsListClass() = default;
    std::vector<std::string> getVecArgsType() override;
    std::vector<std::string> getVecArgsID() override;
    void addNewArg(std::string argType, std::string argID) override;
};

class FormalDeclClass : public BaseClass {
private:
    std::string argType;
    std::string argID;
public:
    FormalDeclClass(std::string type, std::string id);
    ~FormalDeclClass() = default;
    std::string getArgType() override;
    std::string getArgID() override;
};

class ExpClass : public BaseClass {
private:
    std::string type;
    std::string value;
public:
    ExpClass(std::string type, std::string value = std::string());
    ~ExpClass() = default;
    std::string getType() override;
    std::string getValue() override;
};

class NUMClass : public BaseClass {
private:
    std::string value;
public:
    NUMClass(std::string value);
    ~NUMClass() = default;
    std::string getValue() override;
};

class CallClass : public BaseClass {
private:
    std::string type;
public:
    CallClass(std::string type);
    ~CallClass() = default;
    std::string getType() override;
};

class ExpListClass : public BaseClass {
private:
    std::vector<std::string> vecArgsType;
public:
    ExpListClass(std::vector<std::string> vecArgsType = std::vector<std::string>());
    ~ExpListClass() = default;
    std::vector<std::string> getVecArgsType() override;
    void addNewArgType(std::string argType) override;
};



#endif //_RULES_TYPES_
