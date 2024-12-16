//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_DELETESTATEMENT_H
#define SQLITER_DELETESTATEMENT_H

#include <core/binders/statements/Statement.h>
#include <core/binders/statements/Condition.h>
#include <string>

namespace core::binders::statements {
    class DeleteStatement : public Statement {
    public:
        std::string *tableName;
        Condition *condition = nullptr;

        DeleteStatement(std::string *tableName,
                        Condition *condition) : Statement(DELETE_STATEMENT), tableName(tableName),
                                                condition(condition) {}
    };
} // binders

#endif //SQLITER_DELETESTATEMENT_H
