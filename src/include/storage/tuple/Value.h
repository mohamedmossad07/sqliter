//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_VALUE_H
#define SQLITER_VALUE_H
#include <catalog/Column.h>
using namespace catalog;
namespace storage::tuple {

        class Value {
        public:
            ColumnDataType type;
            explicit Value(ColumnDataType type):type(type){}
        };

    } // tuple

#endif //SQLITER_VALUE_H
