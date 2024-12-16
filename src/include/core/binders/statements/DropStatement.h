//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_DROPSTATEMENT_H
#define SQLITER_DROPSTATEMENT_H

#include <core/binders/statements/Statement.h>
#include <string>

namespace core::binders::statements {
    class DropStatement : public Statement {
    public:
        std::string *tableName;

        explicit DropStatement(std::string *tableName) : Statement(DROP_STATEMENT), tableName(tableName) {}
    };
} // binders

#endif //SQLITER_DROPSTATEMENT_H
