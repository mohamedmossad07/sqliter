//
// Created by mohamed on 29/07/23.
//

#ifndef SQLITER_CONDITION_H
#define SQLITER_CONDITION_H

#include <string>

namespace core::binders::statements {
    enum Condition_Operator {
        EQUAL,
        NOT_EQUAL,
        GREATER_THAN,
        LOWER_THAN,
        GREATER_THAN_OR_EQUAL,
        LOWER_THAN_OR_EQUAL
    };
    enum ConditionType {
        SINGLE,
        MULTI
    };
    enum AND_OR {
        AND,
        OR
    };

    class Condition {
    public:
        std::string *key;
        std::string *val;
        Condition_Operator conditionOperator;
        ConditionType conditionType;

        Condition() = default;

        Condition(std::string *key,
                  std::string *val,
                  Condition_Operator conditionOperator) : key(key), val(val), conditionOperator(conditionOperator),
                                                          conditionType(SINGLE) {}
    };

    class MultiCondition : public Condition {
    public:
        Condition *left;
        Condition *right;
        AND_OR andOr;

        MultiCondition(Condition *left,
                       Condition *right,
                       AND_OR andOr) : Condition(), left(left), right(right), andOr(andOr) {
            this->conditionType = MULTI;
        }
    };
} // statements

#endif //SQLITER_CONDITION_H
