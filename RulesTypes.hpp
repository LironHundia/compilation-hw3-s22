#ifndef _RULES_TYPES_
#define _RULES_TYPES_

#include <iostream>
#include <vector>

typedef std::pair<std::string,std::string> FuncArg;

class BaseClass {
public:
    BaseClass();
    virtual ~BaseClass();
    virtual std::string getType() {std::cout << "error with getType()!" << std::endl;}
    virtual std::string getId() {std::cout << "error with getId()!" << std::endl;}
    virtual std::vector<FuncArg> getArgsVector() {std::cout << "error with getArgsVector()!" << std::endl;}
    virtual FuncArg getArg() {std::cout << "error with getArg()!" << std::endl;}
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
    std::vector<FuncArg> args;
public:
    FormalsClass(/*TODO*/);
    ~FormalsClass() override;
    std::vector<FuncArg> getArgsVector();
};

class FormalsListClass : public BaseClass {
private:
    std::vector<FuncArg> args;
public:
    FormalsListClass(/*TODO*/);
    ~FormalsListClass() override;
    std::vector<FuncArg> getArgsVector();
};

class FormalDeclClass : public BaseClass {
private:
    FuncArg arg;
public:
    FormalDeclClass(std::string type, std::string id);
    ~FormalDeclClass() override;
    FuncArg getArg();
};








#endif //_RULES_TYPES_
