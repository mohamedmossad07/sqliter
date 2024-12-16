//
// Created by mohamed on 25/07/23.
//

#ifndef SQLITER_CONSTRAINT_H
#define SQLITER_CONSTRAINT_H

#include <string>

namespace core::binders::statements {
    enum ConstraintType {
        PRIMARY,
        NOT_NULL,
        UNIQUE,
        AUTOINCREMENT,
        DEFAULT
    };

    class Constraint {
    public:
        ConstraintType constraintType;
        std::string *default_val = nullptr;

        explicit Constraint(ConstraintType constraintType) : constraintType(constraintType) {}

        Constraint(ConstraintType constraintType,
                   std::string *default_val) : constraintType(constraintType), default_val(default_val) {}
    };

} // statement

#endif //SQLITER_CONSTRAINT_H
