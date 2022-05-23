#ifndef _TABLE_SCOPE_
#define _TABLE_SCOPE_

#include <iostream>
#include <vector>
#include <list>
#include "TableEntry.hpp"


class TableScope {
private:
    std::list<TableEntry> entries;
public:
    TableScope();
    ~TableScope() = default;
    void pushEntry(std::string id, int offset, std::string type, bool isFunc = false,
                   std::vector<std::string> argsTypes = std::vector<std::string>());
    void popEntry();
	TableEntry& topEntry();
    TableEntry* findEntryInScope(std::string id);
};

#endif //_TABLE_SCOPE_
