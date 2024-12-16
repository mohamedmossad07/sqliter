//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_CREATEQUERYEXECUTER_H
#define SQLITER_CREATEQUERYEXECUTER_H
#include <core/binders/statements/CreateStatement.h>
#include <execution/Executer.h>
using namespace core::binders::statements;

namespace execution {

    class CreateQueryExecuter: public Executer{
    public:
        CreateStatement* createStatement;
        explicit CreateQueryExecuter(CreateStatement* createStatement);
        void execute() override;
    };

} // execution

#endif //SQLITER_CREATEQUERYEXECUTER_H
