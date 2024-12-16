//
// Created by mohamed on 31/07/23.
//

#ifndef SQLITER_DISKMANAGER_H
#define SQLITER_DISKMANAGER_H
#include <string>
#include <fstream>
#include <iostream>
#include <common/config.h>
using  namespace common;
namespace storage {

    class DiskManager {
    public:
        std::string * filename;
        std::fstream db_io;
        explicit DiskManager(std::string* db_file);
        bool readPage(page_id_t pid,char* data);
        bool writePage(page_id_t pid,char* data);
        void shutdown();
    };

} // storage

#endif //SQLITER_DISKMANAGER_H
