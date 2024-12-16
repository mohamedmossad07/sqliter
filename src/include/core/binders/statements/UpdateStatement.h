//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_UPDATESTATEMENT_H
#define SQLITER_UPDATESTATEMENT_H

#include <core/binders/statements/Condition.h>
#include <core/binders/statements/Statement.h>
#include <string>
#include <vector>
#include <utility>

namespace core::binders::statements {
    class KeyValueAssignment {
    public:
        std::string *key;
        std::string *value;

        KeyValueAssignment(std::string *key,
                           std::string *value) : key(key), value(value) {}
    };

    class UpdateStatement : public Statement {
    public:
        std::string *tableName;
        Condition *condition = nullptr;
        std::vector<KeyValueAssignment *> updatekeyValMap;

        UpdateStatement(std::string *tableName, std::vector<KeyValueAssignment *> updatekeyValMap, Condition *condition)
                : Statement(UPDATE_STATEMENT), tableName(tableName), condition(condition),
                  updatekeyValMap(std::move(updatekeyValMap)) {}
    };
} // binders

#endif //SQLITER_UPDATESTATEMENT_H
