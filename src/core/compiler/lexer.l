%{
 #include <core/compiler/parser.hpp>
 #include <core/compiler/Lexer.h>
 #undef YY_DECL
 #define YY_DECL int core::compiler::Lexer::yylex(core::compiler::Parser::semantic_type *lval,core::compiler::Parser::location_type* loc)
using token = core::compiler::Parser::token;
#define yyterminate() return(token::END)
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
#define YY_NO_UNISTD_H
%}
%option debug
%option nodefault
%option yyclass="core::compiler::Lexer"
%option noyywrap
%option c++

%%
%{
yylval = lval;
%}

[ \n\r\t]                          {/*ignore whitespace */}
"CREATE"                              {return (token::CREATE);}
"TABLE"                           {return (token::TABLE);}
"("                               {return (token::OPEN_B);}
")"                                {return (token::CLOSE_B);}
"\""                                 {return (token::DOUBLE_Q);}
"'"                               {return (token::SINGLE_Q);}
"INT"                                   {return (token::INT);}
"TEXT"                               {return (token::TEXT);}
"REAL"                               {return (token::REAL);}
"PRIMARY"                              {return (token::PRIMARY);}
"KEY"                                {return (token::KEY);}
"NOT"                                {return (token::NOT);}
"NULL"                               {return (token::NULL_);}
"AUTOINCREMENT"                     {return (token::AUTOINCREMENT);}
"UNIQUE"                             {return (token::UNIQUE);}
"INNER"                             {return (token::INNER);}
"DEFAULT"                           {return (token::DEFAULT);}
"JOIN"                              {return (token::JOIN);}
"="                                 {return (token::EQUAL);}
"<>"                                 {return (token::NOT_EQUAL);}
">"                                  {return (token::GREATER);}
"<"                                  {return (token::LOWER);}
"<="                                 {return (token::LOWER_OR_EQUAL);}
">="                                {return (token::GREATER_OR_EQUAL);}
"SELECT"                             {return (token::SELECT);}
"*"                                  {return (token::ASTREISK);}
";"                                  {return (token::SEMICOLN);}
"FROM"                                {return (token::FROM);}
"WHERE"                                {return (token::WHERE);}
"ORDER"                                 {return (token::ORDER);}
"BY"                                      {return (token::BY);}
"ASC"                                    {return (token::ASC);}
"DESC"                                  {return (token::DESC);}
"INSERT"                                 {return (token::INSERT);}
"INTO"                                   {return (token::INTO);}
"VALUES"                                   {return (token::VALUES);}
"UPDATE"                                    {return (token::UPDATE);}
"SET"                                    {return (token::SET);}
"DELETE"                                 {return (token::DELETE);}
"SCHEMA"                                 {return (token::SCHEMA);}
"TABLES"                                 {return (token::TABLES);}
"DROP"                                   {return (token::DROP);}
"AND"                                  {return (token::AND);}
"OR"                                   {return (token::OR);}
"EXIT"                                {return (token::EXIT);}
"SOURCE"                              {return (token::SOURCE);}
","                                  {return (token::COMMA);}
"."                                   {return (token::DOT);}
[a-zA-Z][a-zA-Z0-9_]*                { yylval->stringval = new std::string(yytext);  return (token::IDENTIFIER);}
[0-9]+"."[0-9]+                      {yylval->doubleval = std::stod(yytext);  return (token::DOUBLE);}
[0-9]+                               {yylval->intval = std::stoi(yytext); return (token::INTEGER);}
\"[a-zA-Z0-9_ ]*\"                    {yylval->stringval = new std::string(yytext); return (token::STRING);}
\'[a-zA-Z0-9_ ]*\'                   {yylval->stringval = new std::string(yytext); return (token::STRING);}
.                                    {return (token::UNDEFIEND);}
<<EOF>>                              {return (token::END);}
%%

