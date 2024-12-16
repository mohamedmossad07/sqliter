//
// Created by mohamed on 25/07/23.
//

#ifndef SQLITER_COLUMNDEFINITION_H
#define SQLITER_COLUMNDEFINITION_H

#include <string>
#include <core/binders/statements/Constraint.h>

namespace core::binders::statements {
    enum DataType {
        TEXT,
        INT,
        REAL
    };

    class ColumnDefinition {
    public:
        std::string *colName;
        DataType dataType;
        Constraint *constraint;

        ColumnDefinition() = default;

        ColumnDefinition(std::string *colName,
                         DataType dataType,
                         Constraint *constraint) : colName(colName), dataType(dataType), constraint(constraint) {};
    };

} // statements

#endif //SQLITER_COLUMNDEFINITION_H
