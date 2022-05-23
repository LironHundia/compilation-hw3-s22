#include "TableScope.hpp"

TableScope::TableScope() : entries(std::list<TableEntry>()){}

void TableScope::pushEntry(std::string id, int offset, std::string type, bool isFunc, std::vector<std::string> argsTypes) {
    TableEntry newEntry(id, offset, type, isFunc, argsTypes);
    entries.push_back(newEntry);
}

void TableScope::popEntry() {
    entries.pop_back();
}

TableEntry* TableScope::findEntryInScope(std::string id) {
    for (std::list<TableEntry>::iterator it=entries.begin(); it != entries.end(); ++it) {
        //if we found a valid entry in current TableScope
        if (id == (*it).getId()) {
            return &(*it);
        }
    }
    //didn't find any entry in this scope
    return nullptr;
}

TableEntry& TableScope::topEntry(){
	return entries.back();
}
