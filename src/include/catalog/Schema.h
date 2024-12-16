//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_SCHEMA_H
#define SQLITER_SCHEMA_H
#include <catalog/Column.h>
#include <vector>
namespace catalog {

    class Schema {
    public:
        std::vector<Column> columns;
        Schema(std::vector<Column> columns):columns(columns){}
    };

} // catalog

#endif //SQLITER_SCHEMA_H
