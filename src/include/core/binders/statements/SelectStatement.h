//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_SELECTSTATEMENT_H
#define SQLITER_SELECTSTATEMENT_H

#include <core/binders/statements/Statement.h>
#include <core/binders/statements/Condition.h>
#include <string>
#include <utility>
#include <vector>

namespace core::binders::statements {
    enum OrderByType {
        ASC,
        DESC
    };

    class OrderByColumn {
    public:
        OrderByType orderByType;
        std::string *col;

        OrderByColumn(OrderByType orderByType,
                      std::string *col) : orderByType(orderByType), col(col) {}
    };

    class SelectStatement : public Statement {
    public:
        std::string *tableName;
        Condition *condition = nullptr;
        std::vector<std::string *> selectedCols;
        std::vector<OrderByColumn *> orderedCols;
        bool ASTREISK = false;

        SelectStatement(std::string *tableName,
                        Condition *condition,
                        std::vector<std::string *> selectedCols,
                        std::vector<OrderByColumn *> orderedCols) :
                Statement(SELECT_STATEMENT), tableName(tableName), condition(condition),
                selectedCols(std::move(selectedCols)), orderedCols(std::move(orderedCols)) {}

        SelectStatement(std::string *tableName,
                        Condition *condition,
                        std::vector<OrderByColumn *> orderedCols,
                        bool ASTREISK) : Statement(SELECT_STATEMENT), tableName(tableName), condition(condition),
                                         orderedCols(std::move(orderedCols)), ASTREISK(ASTREISK) {
        }
    };
} // binders

#endif //SQLITER_SELECTSTATEMENT_H
