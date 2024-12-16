//
// Created by mohamed on 31/07/23.
//

#include <storage/DiskManager.h>
namespace storage {
    DiskManager::DiskManager(std::string* db_file){
        db_io.open(*db_file, std::ios::in | std::ios::binary);
        if(!db_io.is_open()){
            db_io.open(*db_file,std::ios::out | std::ios::trunc | std::ios::in | std::ios::binary);
        }
    }
    bool DiskManager::readPage(page_id_t pid,char* data){
        int offset = pid * common::PAGE_SIZE;
        db_io.seekp(offset);
        db_io.read(data,PAGE_SIZE);
        if (db_io.bad()) {
            std::cout<<"I/O error while reading\n";
         }
        return false;
    }
    bool DiskManager::writePage(page_id_t pid,char* data){
        int offset = pid * common::PAGE_SIZE;
        db_io.seekp(offset);
        db_io.write(data,PAGE_SIZE);
        if (db_io.bad()) {
            std::cout<<"I/O error while write\n";
         }
        db_io.flush();
        return false;
    }
} // storage