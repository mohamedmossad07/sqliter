//
// Created by mohamed on 01/08/23.
//

#include <storage/Page.h>

namespace storage {
    Page::Page(common::page_id_t pid):pid(pid){
        data = new char [common::PAGE_SIZE];
    }
} // storage