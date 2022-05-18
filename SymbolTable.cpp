#include "SymbolTable.hpp"

TableEntry::TableEntry(std::string id, int offset, std::string type, bool isFunc, std::vector<std::string> argsTypes) :
                       id(id), offset(offset), type(type), isFunc(isFunc), argTypes(argTypes) {}
std::string& TableEntry::getId() {return id;}
int TableEntry::getOffset() {
    return offset;
}
std::string& TableEntry::getType() {
    return type;
}
bool TableEntry::getIsFunc() {
    return isFunc;
}
std::vector<std::string> TableEntry::getArgTypes() {
    return argsTypes;
}

TableScope::TableScope() : entries(std::list<TableEntry>()){}
void TableScope::pushEntry(std::string id, int offset, std::string type, bool isFunc, std::vector<std::string> argsTypes) {
    TableEntry newEntry(id, offset, type, isFunc, argsTypes);
    entries.pushback(newEntry);
}
void TableScope::popEntry() {
    entries.popback();
}

class SymbolTable {
private:
    std::list<TableScope> scopes;
    int offset;
public:
SymbolTable::SymbolTable() : scopes(std::list<TableScope>()) , offset(0) {}
void SymbolTable::pushScope() {
    TableScope newScope;
    scopes.pushback(newScope);
}
void SymbolTable::popScope() {
    scopes.popback();
}
TableScope& SymbolTable::getTopScope() {
    return scopes.back();
}
//offset management
void SymbolTable::decOffset() {
    offset -= 1;
}
void SymbolTable::incOffset() {
    offset += 1;
}
int SymbolTable::getOffset() {
    return offset;
}
