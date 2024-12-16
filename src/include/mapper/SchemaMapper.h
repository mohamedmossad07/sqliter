//
// Created by mohamed on 01/08/23.
//

#ifndef SQLITER_SCHEMAMAPPER_H
#define SQLITER_SCHEMAMAPPER_H
#include <mapper/Mapper.h>
#include <catalog/Schema.h>
using namespace catalog;

namespace mapper {

    class SchemaMapper : public Mapper{
    public:
        SchemaMapper() = delete;
        static int map(Schema * obj, char * data);
        static Schema*  unmap(char * data, Schema * obj);

    };

} // mapper

#endif //SQLITER_SCHEMAMAPPER_H
