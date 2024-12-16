//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_TUPLE_H
#define SQLITER_TUPLE_H
#include <utility>
#include <vector>
#include <storage/tuple/Value.h>

namespace storage::tuple {

        class Tuple {
        public:
            std::vector<Value> values;
            explicit Tuple(std::vector<Value> values):values(std::move(values)){}
        };

    } // tuple

#endif //SQLITER_TUPLE_H
