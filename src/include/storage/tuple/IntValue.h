//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_INTVALUE_H
#define SQLITER_INTVALUE_H
#include <storage/tuple/Value.h>
#include <catalog/Column.h>
using namespace catalog;

namespace storage {
    namespace tuple {

        class IntValue : public Value{
        public:
            int value;
            IntValue(int value):Value(ColumnDataType::INT),value(value){}
        };

    } // storage
} // tuple

#endif //SQLITER_INTVALUE_H
