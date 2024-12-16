#ifndef SRC_INCLUDE_CORE_COMPILER_COMMAND_PROCESSOR_H_
#define SRC_INCLUDE_CORE_COMPILER_COMMAND_PROCESSOR_H_

#include <string>
#include <vector>
#include <core/interface/SqlInputBuffer.h>
#include <core/compiler/parser.hpp>
#include <core/compiler/Lexer.h>
#include <sstream>
#include <core/binders/Query.h>
#include <exceptions/ParserException.h>

using namespace core::binders;
using namespace core::interface;
namespace core::compiler {
    class CommandsProcessor {
    public:
        static std::vector<Query *> queries;

        CommandsProcessor() = delete;

        static std::vector<Query *> parseText(SqlInputBuffer *);
    };
}
#endif /* SRC_INCLUDE_CORE_COMPILER_COMMAND_PROCESSOR_H_ */
