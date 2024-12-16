//
// Created by mohamed on 31/07/23.
//

#ifndef SQLITER_BUFFEPOOL_H
#define SQLITER_BUFFEPOOL_H
#include <common/config.h>
#include <storage/Page.h>
#include <storage/DiskManager.h>
#include <map>
using  namespace common;

namespace storage {

    class BufferpoolManager {
    public:
        DiskManager* diskManager;
        std::map<common::page_id_t,Page*> pages;
        BufferpoolManager(DiskManager* diskManager);
        Page* newPage(page_id_t page_id);
        Page* fetchPage(page_id_t page_id);
        bool flushPage(page_id_t page_id);
        bool flushAllPages();
    };

} // storage

#endif //SQLITER_BUFFEPOOL_H
