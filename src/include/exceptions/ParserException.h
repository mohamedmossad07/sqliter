//
// Created by mohamed on 29/07/23.
//

#ifndef SQLITER_PARSEREXCEPTION_H
#define SQLITER_PARSEREXCEPTION_H
#include <core/compiler/parser.hpp>
#include <exception>
#include <string>
#include <utility>
using namespace core::compiler;

namespace exceptions {

class ParserException : public std::exception{
public:
    int location;
    std::string  msg;
    ParserException(const Parser::location_type& loc,std::string  msg):location(loc.begin.column),msg(std::move(msg)){}
    const char * what() const noexcept override;
    };

} // exceptions

#endif //SQLITER_PARSEREXCEPTION_H
