//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_REALVALUE_H
#define SQLITER_REALVALUE_H
#include <storage/tuple/Value.h>
#include <catalog/Column.h>
using namespace catalog;
namespace storage {
    namespace tuple {

        class RealValue: public Value{
        public:
            double value;
            RealValue(double value):Value(ColumnDataType::REAL),value(value){}
        };

    } // storage
} // tuple

#endif //SQLITER_REALVALUE_H
