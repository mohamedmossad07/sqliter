//
// Created by mohamed on 01/08/23.
//

#ifndef SQLITER_COLUMNMAPPER_H
#define SQLITER_COLUMNMAPPER_H
#include <mapper/Mapper.h>
#include <catalog/Column.h>
#include <cstring>

using namespace catalog;
namespace mapper {

    class ColumnMapper : public Mapper{
    public:
        ColumnMapper() = delete;
        static int map(Column * obj, char * data);
        static Column*  unmap(char * data, Column * obj);
    };

} // mapper

#endif //SQLITER_COLUMNMAPPER_H
