//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_STATEMENT_H
#define SQLITER_STATEMENT_H

#include <core/binders/SqlQuery.h>

namespace core::binders::statements {
    enum StatementType {
        INVALID_STATEMENT,        // invalid statement type
        SELECT_STATEMENT,         // select statement type
        INSERT_STATEMENT,         // insert statement type
        UPDATE_STATEMENT,         // update statement type
        CREATE_STATEMENT,         // create statement type
        DELETE_STATEMENT,         // delete statement type
        DROP_STATEMENT           // drop statement type
    };

    class Statement : public SqlQuery {
    public:
        StatementType statement_type;

        explicit Statement(StatementType statement_type) : statement_type(statement_type) {}
    };
} // binders

#endif //SQLITER_STATEMENT_H
