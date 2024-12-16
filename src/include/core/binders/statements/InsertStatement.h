//
// Created by mohamed on 26/07/23.
//

#ifndef SQLITER_INSERTSTATEMENT_H
#define SQLITER_INSERTSTATEMENT_H

#include <core/binders/statements/Statement.h>
#include <string>
#include <utility>
#include <vector>

namespace core::binders::statements {

    class InsertStatement : public Statement {
    public:
        std::string *tableName;
        std::vector<std::string *> colNames;
        std::vector<std::string *> values;

        InsertStatement(std::string *tableName, std::vector<std::string *> colNames, std::vector<std::string *> values)
                :
                Statement(INSERT_STATEMENT), tableName(tableName), colNames(std::move(colNames)),
                values(std::move(values)) {}
    };

} // statements

#endif //SQLITER_INSERTSTATEMENT_H
