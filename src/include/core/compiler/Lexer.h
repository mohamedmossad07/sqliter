/*
 * Lexer.h
 *
 *  Created on: Jul 17, 2023
 *      Author: mohamed
 */

#ifndef SRC_INCLUDE_CORE_COMPILER_LEXER_H_
#define SRC_INCLUDE_CORE_COMPILER_LEXER_H_

#include <iostream>
#include <string>

#if !defined(yyFlexLexerOnce)

#include <FlexLexer.h>

#endif

#include <fstream>
#include <core/compiler/parser.hpp>
#include <core/compiler/location.hh>

namespace core::compiler {
    class Lexer : public yyFlexLexer {
    public:
        explicit Lexer(std::istream *in) : yyFlexLexer(in) {

            loc = new Parser::location_type();
        }

        virtual int yylex(Parser::semantic_type *yylval, core::compiler::Parser::location_type *loc);

    private:
        /* yyval ptr */
        Parser::semantic_type *yylval = nullptr;
        Parser::location_type *loc = nullptr;
    };
} /* end namespace core */



#endif /* SRC_INCLUDE_CORE_COMPILER_LEXER_H_ */
