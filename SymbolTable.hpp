#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_

#include <iostream>

class TableEntry {
private:
    std::string id;
    int offset;
    std::string type;
    bool isFunc;
    std::vector<std::string> argsTypes;
public:
    TableEntry(std::string id, int offset, std::string type, bool isFunc = false,
               std::vector<std::string> argsTypes = std::vector<std::string>());
    ~TableEntry();
    std::string& getId();
    int getOffset();
    std::string& getType();
    bool getIsFunc();
    std::vector<std::string> getArgTypes();
};

class TableScope {
private:
    std::list<TableEntry> entries;
public:
    TableScope();
    ~TableScope();
    void pushEntry(std::string id, int offset, std::string type, bool isFunc = false,
               std::vector<std::string> argsTypes = std::vector<std::string>());
    void popEntry();
};

class SymbolTable {
private:
    std::list<TableScope> scopes;
public:
    SymbolTable();
    ~SymbolTable();
    void pushScope();
    void popScope();
};


class offset {

};
#endif //_SYMBOL_TABLE_
