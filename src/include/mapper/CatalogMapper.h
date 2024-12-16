//
// Created by mohamed on 01/08/23.
//

#ifndef SQLITER_CATALOGMAPPER_H
#define SQLITER_CATALOGMAPPER_H
#include <mapper/Mapper.h>
#include <catalog/Catalog.h>

using namespace catalog;
namespace mapper {

    class CatalogMapper : public Mapper{
    public:
        CatalogMapper() = delete;
        static int map(Catalog * obj, char * data);
        static Catalog*  unmap(char * data, Catalog * obj);
    };

} // mapper

#endif //SQLITER_CATALOGMAPPER_H
