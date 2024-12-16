//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_CREATESTATEMENT_H
#define SQLITER_CREATESTATEMENT_H

#include <core/binders/statements/Statement.h>
#include <core/binders/statements/Constraint.h>
#include <core/binders/statements/ColumnDefinition.h>
#include <string>
#include <vector>

 namespace core::binders::statements {
    class CreateStatement : public Statement {
    public:
        std::string *tableName;
        std::vector<ColumnDefinition *> columnDefinitionLst;

        CreateStatement(std::string *tableName, const std::vector<ColumnDefinition *> &columnDefinitionLst) :
                Statement(CREATE_STATEMENT), tableName(tableName), columnDefinitionLst(columnDefinitionLst) {};
    };
} // binders

#endif //SQLITER_CREATESTATEMENT_H
