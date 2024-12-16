//
// Created by mohamed on 01/08/23.
//

#ifndef SQLITER_TABLEDEFINITIONMAPPER_H
#define SQLITER_TABLEDEFINITIONMAPPER_H
#include <mapper/Mapper.h>
#include <catalog/TableDefinition.h>

using namespace catalog;
namespace mapper {

    class TableDefinitionMapper : public Mapper{
    public:
    TableDefinitionMapper() = delete;
    static int map(TableDefinition * obj, char * data);
    static TableDefinition*  unmap(char * data, TableDefinition * obj);
};

} // mapper

#endif //SQLITER_TABLEDEFINITIONMAPPER_H
