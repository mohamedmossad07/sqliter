//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_TEXTVALUE_H
#define SQLITER_TEXTVALUE_H
#include <storage/tuple/Value.h>
#include <string>
namespace storage {
    namespace tuple {

        class TextValue: public Value{
        public:
            std::string value;
            TextValue(std::string value):Value(ColumnDataType::TEXT),value(value){}
        };

    } // storage
} // tuple

#endif //SQLITER_TEXTVALUE_H
