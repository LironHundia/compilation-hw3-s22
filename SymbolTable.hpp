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
    void pushEntry(TableEntry newEntry);
    void popEntry();
    TableEntry* findEntryInScope(std::string id);
};

class SymbolTable {
private:
    std::list<TableScope> scopes;
    int offset;
public:
    SymbolTable();
    ~SymbolTable();
    void pushScope();
    void popScope();
    TableScope& getTopScope();
    //TODO: ADD A FIND FUNCTION!!! --> return pointer to the right entry if var exist. if not --> returns null.
    TableEntry* findEntryInTable(std::string id);
    //offset management
    void decOffset();
    void incOffset();
    int getOffset();
};

#endif //_SYMBOL_TABLE_
