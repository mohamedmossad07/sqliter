//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_COLUMN_H
#define SQLITER_COLUMN_H
#include <string>
#include <utility>
namespace catalog {
    enum ColumnDataType{
        INT,
        TEXT,
        REAL
    };
    class Column {
    public:
        std::string name;
        ColumnDataType type;
        Column(std::string name,ColumnDataType type):name(std::move(name)),type(type){}
    };

} // catalog

#endif //SQLITER_COLUMN_H
