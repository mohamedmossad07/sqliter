//
// Created by mohamed on 30/07/23.
//

#ifndef SQLITER_EXECUTIONMANAGER_H
#define SQLITER_EXECUTIONMANAGER_H
#include <execution/Executer.h>
#include <core/binders/Query.h>
#include <vector>
using namespace core::binders;
namespace execution {

    class ExecutionManager {
    public:
        static void execute(std::vector<Query*> qs);
    };

} // execution

#endif //SQLITER_EXECUTIONMANAGER_H
