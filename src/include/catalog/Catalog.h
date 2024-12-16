//
// Created by mohamed on 31/07/23.
//

#ifndef SQLITER_CATALOG_H
#define SQLITER_CATALOG_H
#include <catalog/TableDefinition.h>
#include <storage/BufferpoolManager.h>
#include <common/config.h>
#include <map>
#include <string>
using namespace storage;
using namespace common;
namespace catalog {

    class Catalog {
    public:
        BufferpoolManager* bpm;
        std::map<std::string*,TableDefinition*> tables;

        static Catalog* getCatalog(BufferpoolManager* bpm);
        void createTable(std::string* table,TableDefinition* def);
        void save();
        TableDefinition getTableDefinition(std::string table);
        Schema* getTableSchema(std::string table);
    private:
        static Catalog* instance;
        Catalog(BufferpoolManager* bpm);
    };

} // catalog

#endif //SQLITER_CATALOG_H
