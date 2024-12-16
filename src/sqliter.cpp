#include <core/interface/SqlInterface.h>
#include <iostream>
#include <core/interface/SqlInputBuffer.h>
#include <core/compiler/Lexer.h>
#include <fstream>
#include <sstream>
#include <core/compiler/parser.hpp>
#include <core/compiler/commandsProcessor.h>
#include <storage/DiskManager.h>
#include <storage/BufferpoolManager.h>
#include <catalog/Column.h>
#include <cstring>
#include <mapper/ColumnMapper.h>
using namespace storage;
using namespace mapper;
using namespace catalog;
using namespace core::interface;
using namespace core::compiler;
using namespace core::binders::statements;

int main(int argc, char **argv) {
	std::cout<< "SQLiter\n"<<
			"Enter \".help\" for usage hints.\n"<<
			"Connected to a transient in-memory database.\n"<<
			"Use \".open FILENAME\" to reopen on a persistent database.\n";
    int counter = 22;
    std::string fn("/home/mohamed/Documents/projects/sqliter/test.mm");
//    DiskManager* diskManager = new DiskManager(&fn);
//    BufferpoolManager* bpm = new BufferpoolManager(diskManager);
    char data[20];
    ColumnMapper::map(new Column("email",ColumnDataType::TEXT),data);
    //    while (--counter){
//        SqlInputBuffer *input = SqlInterface::acceptInput();
//        std::vector<Query *> rt = CommandsProcessor::parseText(input);
//    }
//    std::istringstream ss("CREATE table x (email REAL,name TEXT,age INT);");
//    std::ifstream in_("/home/mohamed/Documents/projects/sqliter/src/test.txt");
//    auto* l = new Lexer(&ss);
//    auto* parser = new Parser(l);
//    parser->parse();
//	delete l;
	std::cout<<std::endl;
	return 0;
}
