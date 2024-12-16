//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_SQL_QUERY_H
#define SQLITER_SQL_QUERY_H

#include <core/binders/Query.h>

namespace core::binders {

    class SqlQuery : public Query {
    public:
        SqlQuery() : Query(SQL_QUERY) {}
    };

} // binders

#endif //SQLITER_SQL_QUERY_H
