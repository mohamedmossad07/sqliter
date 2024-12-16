//
// Created by mohamed on 31/07/23.
//

#ifndef SQLITER_CONFIG_H
#define SQLITER_CONFIG_H
#include <cstdint>
namespace common{
    typedef uint32_t page_id_t;

    static constexpr int INVALID_PAGE_ID = -1;
    static constexpr int BUFFER_POOL_SIZE = 6;
    static constexpr uint16_t PAGE_SIZE = 1024*4;//4KB
    static constexpr page_id_t CATALOG_PAGE_ID = 1;

}//end common
#endif //SQLITER_CONFIG_H
