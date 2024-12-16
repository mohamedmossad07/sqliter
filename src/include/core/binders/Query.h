//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_QUERY_H
#define SQLITER_QUERY_H

namespace core::binders {
    enum QueryType {
        SQL_QUERY,
        META_QUERY
    };

    class Query {
    public:
        QueryType queryType;

        explicit Query(QueryType queryType) : queryType(queryType) {}
    };
} // binders

#endif //SQLITER_QUERY_H
