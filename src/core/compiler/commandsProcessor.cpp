#include <core/compiler/commandsProcessor.h>
#include <core/binders/statements/InsertStatement.h>
#include <core/binders/statements/SelectStatement.h>
#include <execution/ExecutionManager.h>
#include <execution/CreateQueryExecuter.h>
#include <core/binders/MetaQuery.h>
#include <storage/tuple/Tuple.h>

using namespace core::compiler;
using namespace core::binders;
using namespace execution;
std::vector<Query *> CommandsProcessor::queries = std::vector<Query *>();

std::vector<Query *> CommandsProcessor::parseText(SqlInputBuffer *buffer) {
    std::istringstream inputStream(buffer->getInput());
    Lexer *l = new Lexer(&inputStream);
    Parser *parser = new Parser(l, queries);
    try {
        parser->parse();
    }catch (exceptions::ParserException &e){
        std::cout<<e.msg<< " at "<<e.location<<std::endl;
    }
//    CreateQueryExecuter* e = new CreateQueryExecuter((CreateStatement*) queries.at(0));
    std::vector<Query *> copy = std::move(queries);
    queries.clear();
    delete l;
    delete parser;
    return copy;
 }
