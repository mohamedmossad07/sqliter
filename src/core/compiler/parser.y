%skeleton "lalr1.cc"
%debug
%defines
%define api.namespace {core::compiler}
%define api.parser.class {Parser}
%locations
%code requires{
#include <string>
#include <iostream>
#include <core/binders/statements/Constraint.h>
#include <core/binders/statements/ColumnDefinition.h>
#include <core/binders/statements/CreateStatement.h>
#include <core/binders/statements/InsertStatement.h>
#include <core/binders/statements/DropStatement.h>
#include <core/binders/statements/UpdateStatement.h>
#include <core/binders/statements/DeleteStatement.h>
#include <core/binders/statements/SelectStatement.h>
#include <core/binders/statements/Condition.h>
#include <core/binders/Query.h>
#include <core/binders/MetaQuery.h>
#include <core/binders/SqlQuery.h>
using namespace core::binders::statements;
using namespace core::binders;
namespace core::compiler {
    class Lexer;
}
// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
}

%parse-param {Lexer* lexer}
%parse-param {std::vector<Query*>& queries}
%code {
#include <exceptions/ParserException.h>
#include <core/compiler/Lexer.h>
#undef yylex
#define yylex lexer->yylex
}
%union
{
std::string *stringval;
int intval;
double doubleval;
CreateStatement* CreateStatementType;
InsertStatement* InsertStatementType;
DropStatement* DropStatementType;
UpdateStatement* UpdateStatementType;
DeleteStatement* DeleteStatementType;
SelectStatement* SelectStatementType;
ColumnDefinition* ColumnDefinitionType;
Constraint* ConstraintType_;
DataType DataType_;
Query* QueryType_;
SqlQuery* SqlQueryType_;
KeyValueAssignment* KeyValueAssignmentType_;
MetaQuery* MetaQueryType_;
NoParamMetaQuery* NoParamMetaQueryType_;
OneParamMetaQuery* OneParamMetaQueryType_;
MetaQueryKeyword MetaQueryKeywordType_;
Condition* ConditionType_;
Condition_Operator Condition_OperatorType_;
AND_OR AND_ORType_;
OrderByType OrderByType_;
char * CharType;
OrderByColumn * OrderByColumnType;
}
%code {
 std::vector<ColumnDefinition*> columnDefinitionLst;
 std::vector<std::string*> columnInsertedLst;
 std::vector<std::string*> columnSelectedLst;
 std::vector<OrderByColumn*> columnOrderedLst;
 std::vector<std::string*> valuesInsertedLst;
std::vector<KeyValueAssignment*> updatekeyValMap;
}
%token END  0 "END OF FILE"
%token CREATE
%token TABLE
%token OPEN_B
%token CLOSE_B
%token DOUBLE_Q
%token SINGLE_Q
%token INT
%token REAL
%token TEXT
%token PRIMARY
%token KEY
%token NOT
%token NULL_
%token AUTOINCREMENT
%token UNIQUE
%token INNER
%token DEFAULT
%token JOIN
%token EQUAL
%token NOT_EQUAL
%token GREATER
%token LOWER
%token LOWER_OR_EQUAL
%token GREATER_OR_EQUAL
%token SELECT
%token ASTREISK
%token SEMICOLN
%token FROM
%token WHERE
%token ORDER
%token BY
%token ASC
%token DESC
%token INSERT
%token INTO
%token VALUES
%token UPDATE
%token SET
%token AND
%token OR
%token DROP
%token DELETE
%token <stringval> IDENTIFIER
%token <intval> INTEGER
%token <stringval> STRING
%token <doubleval> DOUBLE
%token COMMA
%token DOT
%token <MetaQueryKeywordType_> SCHEMA
%token <MetaQueryKeywordType_> TABLES
%token <MetaQueryKeywordType_> EXIT
%token <MetaQueryKeywordType_> SOURCE
%token UNDEFIEND
%type <CreateStatementType> create_table_query
%type <ColumnDefinitionType> column_definition
%type <ColumnDefinitionType> column_definition_list
%type <DataType_> data_type
%type <ConstraintType_> constraint
%type <stringval> value
%type <QueryType_> query
%type <DropStatementType> drop_table_query
%type <InsertStatementType> insert_query
%type <SelectStatementType> select_query
%type <UpdateStatementType> update_query
%type <DeleteStatementType> delete_query
%type <SqlQueryType_> sql_query
%type <KeyValueAssignmentType_> assignment
%type <MetaQueryType_> meta_query
%type <MetaQueryKeywordType_> meta_shared_tokens
%type <NoParamMetaQueryType_> no_param_meta
%type <OneParamMetaQueryType_> one_param_meta
%type <ConditionType_> conditional_where
%type <ConditionType_> conditional_assignments
%type <ConditionType_> conditional_assignment
%type <Condition_OperatorType_> conditional_operator
%type <AND_ORType_> and_or_operator
%type <CharType> select_list
%type <OrderByColumnType> order_by_col
%type <OrderByType_> optional_order_type

%start S
%%

S
: queries END
;
queries
: %empty
| queries query
{
queries.push_back($query);
}
;
query
: meta_query
{
  $$ =  $meta_query;
}
| sql_query SEMICOLN
{
$$ = $sql_query;
columnDefinitionLst.clear();
columnInsertedLst.clear();
columnSelectedLst.clear();
columnOrderedLst.clear();
valuesInsertedLst.clear();
updatekeyValMap.clear();
}
;
meta_query
: DOT no_param_meta
{
$$ =  $no_param_meta;
}
| DOT one_param_meta
{
$$ =   $one_param_meta;
}
;
no_param_meta
: meta_shared_tokens
{
$$ =  new NoParamMetaQuery($meta_shared_tokens);
}
;
one_param_meta
: meta_shared_tokens IDENTIFIER
{
$$ = new OneParamMetaQuery($meta_shared_tokens,$IDENTIFIER);
}
;
meta_shared_tokens
: SCHEMA
{
$$ = MetaQueryKeyword::SCHEMA;
}
| TABLES
{
$$ = MetaQueryKeyword::TABLES;
}
| EXIT
{
$$ = MetaQueryKeyword::EXIT;
}
| SOURCE
{
$$ = MetaQueryKeyword::SOURCE;
}
;
sql_query
: create_table_query
{
$$ = $create_table_query;
}
| drop_table_query
{
$$ = $drop_table_query;
}
| insert_query
{
$$ = $insert_query;
}
| select_query
{
$$ = $select_query;
}
| update_query
{
$$ = $update_query;
}
| delete_query
{
$$ = $delete_query;
}
;
create_table_query
: CREATE TABLE IDENTIFIER OPEN_B column_definition_list CLOSE_B
{
$$ = new CreateStatement($IDENTIFIER,columnDefinitionLst);
columnDefinitionLst.clear();
}
;
column_definition_list
: column_definition
{
columnDefinitionLst.push_back($column_definition);
}
| column_definition_list COMMA column_definition
{
columnDefinitionLst.push_back($column_definition);}
;
column_definition
: IDENTIFIER data_type constraint
{
$$ = new ColumnDefinition($IDENTIFIER,$data_type,$constraint);
}
;
data_type
: TEXT {
$$ = DataType::TEXT;
}
| INT {
$$ = DataType::INT;
}
| REAL
{
$$ = DataType::REAL;
}
;
constraint
: %empty {
$$ = nullptr;
}
| PRIMARY KEY
{
$$ = new Constraint(ConstraintType::PRIMARY);
}
| NOT NULL_
{
$$ = new Constraint(ConstraintType::NOT_NULL);
}
| UNIQUE
{
$$=new Constraint(ConstraintType::UNIQUE);
}

| AUTOINCREMENT
{
$$=new Constraint(ConstraintType::AUTOINCREMENT);
}
| DEFAULT value
{
$$=new Constraint(ConstraintType::DEFAULT,new std::string(*$value));
}
;
drop_table_query
: DROP TABLE IDENTIFIER
{
$$ = new DropStatement($IDENTIFIER);
}
;
insert_query
: INSERT INTO IDENTIFIER column_inserted VALUES OPEN_B values_list CLOSE_B
{
$$ = new InsertStatement($IDENTIFIER,columnInsertedLst,valuesInsertedLst);
}
;
column_inserted
: %empty
| OPEN_B columns_comma_seperated_list CLOSE_B
;
columns_comma_seperated_list
: IDENTIFIER
{
columnInsertedLst.push_back($IDENTIFIER);
columnSelectedLst.push_back($IDENTIFIER);
 }
| columns_comma_seperated_list COMMA  IDENTIFIER
{
columnInsertedLst.push_back($IDENTIFIER);
columnSelectedLst.push_back($IDENTIFIER);
 }
;
values_list
: value
{
valuesInsertedLst.push_back($value);
}
| values_list COMMA value
{
valuesInsertedLst.push_back($value);
}
;
update_query
: UPDATE IDENTIFIER SET comma_sperated_assignments conditional_where
{
$$ = new UpdateStatement($IDENTIFIER,updatekeyValMap,$conditional_where);
}
;
select_query
: SELECT select_list FROM IDENTIFIER conditional_where optional_order
{
if(*$select_list == '*'){
$$ = new SelectStatement($IDENTIFIER,$conditional_where,columnOrderedLst,true);
}else{
$$ = new SelectStatement($IDENTIFIER,$conditional_where,columnSelectedLst,columnOrderedLst);
}
$select_list = nullptr;
}
;
optional_order
: %empty
| ORDER BY order_by_col_list
;
order_by_col
: IDENTIFIER optional_order_type
{
$$ = new OrderByColumn($optional_order_type,$IDENTIFIER);
}
;
order_by_col_list
: order_by_col
{
columnOrderedLst.push_back($order_by_col);
}
| order_by_col_list COMMA order_by_col
{
columnOrderedLst.push_back($order_by_col);
}
;
optional_order_type
: %empty
{
}
| ASC
{
$$ = OrderByType::ASC;
}
| DESC
{
$$ = OrderByType::ASC;
}
;
select_list
: ASTREISK
{
$$ = new char('*');
}
| columns_comma_seperated_list
{
$$ = nullptr;
}
;
delete_query
: DELETE FROM IDENTIFIER conditional_where
{
$$ = new DeleteStatement($IDENTIFIER,$conditional_where);
}
;
conditional_where
: %empty
{
$$ = nullptr;
}
| WHERE conditional_assignments
{
$$ = $conditional_assignments;
}
;
conditional_assignments
: conditional_assignment
{
$$ = $conditional_assignment;
}
| conditional_assignment and_or_operator conditional_assignments[cs]
{
$$  = new MultiCondition($conditional_assignment,$cs,$and_or_operator);
}
;
conditional_assignment
: IDENTIFIER conditional_operator value
{
$$ = new Condition($IDENTIFIER,$value,$conditional_operator);
}
;
conditional_operator
: EQUAL
{
$$ = Condition_Operator::EQUAL;
}
| NOT_EQUAL
{
$$ = Condition_Operator::NOT_EQUAL;
}
| GREATER
{
$$ = Condition_Operator::GREATER_THAN;
}
| LOWER
{
$$ = Condition_Operator::LOWER_THAN;
}
| LOWER_OR_EQUAL
{
$$ = Condition_Operator::LOWER_THAN_OR_EQUAL;
}
| GREATER_OR_EQUAL
{
$$ = Condition_Operator::GREATER_THAN_OR_EQUAL;
}
;
and_or_operator
: AND
{
$$ = AND_OR::AND;
}
| OR
{
$$ = AND_OR::OR;
}
;
comma_sperated_assignments
: assignment
{
updatekeyValMap.push_back($assignment);
}
| comma_sperated_assignments COMMA assignment
{
updatekeyValMap.push_back($assignment);
}
;
assignment
: IDENTIFIER EQUAL value
{
$$ = new KeyValueAssignment($IDENTIFIER,$value);
}
;
value
: STRING
{
$$ = new std::string(*$STRING);
}
| INTEGER
{
$$ = new std::string(std::to_string($INTEGER));
}
| DOUBLE
{
$$ = new std::string(std::to_string($DOUBLE));
}
;
%%
void core::compiler::Parser::error(const location_type& loc,const std::string& msg){
 	throw exceptions::ParserException(loc,msg);
}