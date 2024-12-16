//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_EXECUTIONMANAGER_H
#define SQLITER_EXECUTIONMANAGER_H
#include <execution/Executer.h>
#include <core/binders/Query.h>
#include <core/binders/SqlQuery.h>
#include <core/binders/MetaQuery.h>

#include <vector>
using namespace core::binders;
namespace execution {

    class ExecutionManager {
    public:
        static void execute(std::vector<Query*> qs);
    private:
        static void executeSqlQuery(SqlQuery* q);
        static void executeMetaQuery(MetaQuery* q);
    };

} // execution

#endif //SQLITER_EXECUTIONMANAGER_H
