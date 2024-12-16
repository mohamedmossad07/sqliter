//
// Created by mohamed on 01/08/23.
//

#ifndef SQLITER_MAPPER_H
#define SQLITER_MAPPER_H
#include <storage/Page.h>
#include <cstring>
using namespace storage;
namespace mapper {

    class Mapper {
    public:
        Mapper() = delete;
        virtual int map(void * obj, char * data) = 0;
        virtual void*  unmap(char * data, void * obj) = 0;
    };

} // mapper

#endif //SQLITER_MAPPER_H
