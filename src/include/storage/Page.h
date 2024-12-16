//
// Created by mohamed on 01/08/23.
//

#ifndef SQLITER_PAGE_H
#define SQLITER_PAGE_H
#include <common/config.h>
namespace storage {

    class Page {
    public:
        char * data;
        common::page_id_t pid;
        common::page_id_t next_pid;
        Page(common::page_id_t pid);
    };

} // storage

#endif //SQLITER_PAGE_H
