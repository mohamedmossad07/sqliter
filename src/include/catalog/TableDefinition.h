//
// Created by mohamed on 31/07/23.
//

#ifndef SQLITER_TABLEDEFINITION_H
#define SQLITER_TABLEDEFINITION_H
#include <catalog/Schema.h>
#include <common/config.h>
namespace catalog {

    class TableDefinition {
    public:
        int startPage;
        int endPage;
        Schema schema;
        TableDefinition(Schema schema):schema(schema),startPage(common::INVALID_PAGE_ID),endPage(common::INVALID_PAGE_ID){}
    };

} // catalog

#endif //SQLITER_TABLEDEFINITION_H
