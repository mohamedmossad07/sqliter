//
// Created by mohamed on 24/07/23.
//

#ifndef SQLITER_METAQUERY_H
#define SQLITER_METAQUERY_H

#include <core/binders/Query.h>
#include <core/binders/statements/Statement.h>
#include <string>

namespace core::binders {
    enum MetaQueryType {
        NO_PARAM_QUERY,
        ONE_PARAM_QUERY
    };
    enum MetaQueryKeyword {
        TABLES,
        EXIT,
        SCHEMA,
        SOURCE,
    };

    class MetaQuery : public Query {
    public:
        MetaQueryType queryType;

        explicit MetaQuery(MetaQueryType queryType) : Query(META_QUERY), queryType(queryType) {}
    };

    class NoParamMetaQuery : public MetaQuery {
    public:
        MetaQueryKeyword metaQueryKeyword;

        explicit NoParamMetaQuery(MetaQueryKeyword metaQueryKeyword) : MetaQuery(MetaQueryType::NO_PARAM_QUERY),
                                                                       metaQueryKeyword(metaQueryKeyword) {}
    };

    class OneParamMetaQuery : public MetaQuery {
    public:
        MetaQueryKeyword metaQueryKeyword;
        std::string *param;

        OneParamMetaQuery(MetaQueryKeyword metaQueryKeyword, std::string *param) : MetaQuery(
                MetaQueryType::ONE_PARAM_QUERY), metaQueryKeyword(metaQueryKeyword), param(param) {}
    };
} // core
#endif //SQLITER_METAQUERY_H
