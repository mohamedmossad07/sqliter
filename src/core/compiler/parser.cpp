// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 39 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"

#include <exceptions/ParserException.h>
#include <core/compiler/Lexer.h>
#undef yylex
#define yylex lexer->yylex
#line 73 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"

 std::vector<ColumnDefinition*> columnDefinitionLst;
 std::vector<std::string*> columnInsertedLst;
 std::vector<std::string*> columnSelectedLst;
 std::vector<OrderByColumn*> columnOrderedLst;
 std::vector<std::string*> valuesInsertedLst;
std::vector<KeyValueAssignment*> updatekeyValMap;

#line 61 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
namespace core { namespace compiler {
#line 154 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer* lexer_yyarg, std::vector<Query*>& queries_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      queries (queries_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 4: // queries: queries query
#line 171 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
queries.push_back((yystack_[0].value.QueryType_));
}
#line 630 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 5: // query: meta_query
#line 177 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
  (yylhs.value.QueryType_) =  (yystack_[0].value.MetaQueryType_);
}
#line 638 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 6: // query: sql_query SEMICOLN
#line 181 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.QueryType_) = (yystack_[1].value.SqlQueryType_);
columnDefinitionLst.clear();
columnInsertedLst.clear();
columnSelectedLst.clear();
columnOrderedLst.clear();
valuesInsertedLst.clear();
updatekeyValMap.clear();
}
#line 652 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 7: // meta_query: DOT no_param_meta
#line 193 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.MetaQueryType_) =  (yystack_[0].value.NoParamMetaQueryType_);
}
#line 660 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 8: // meta_query: DOT one_param_meta
#line 197 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.MetaQueryType_) =   (yystack_[0].value.OneParamMetaQueryType_);
}
#line 668 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 9: // no_param_meta: meta_shared_tokens
#line 203 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.NoParamMetaQueryType_) =  new NoParamMetaQuery((yystack_[0].value.MetaQueryKeywordType_));
}
#line 676 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 10: // one_param_meta: meta_shared_tokens IDENTIFIER
#line 209 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.OneParamMetaQueryType_) = new OneParamMetaQuery((yystack_[1].value.MetaQueryKeywordType_),(yystack_[0].value.stringval));
}
#line 684 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 11: // meta_shared_tokens: SCHEMA
#line 215 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.MetaQueryKeywordType_) = MetaQueryKeyword::SCHEMA;
}
#line 692 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 12: // meta_shared_tokens: TABLES
#line 219 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.MetaQueryKeywordType_) = MetaQueryKeyword::TABLES;
}
#line 700 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 13: // meta_shared_tokens: EXIT
#line 223 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.MetaQueryKeywordType_) = MetaQueryKeyword::EXIT;
}
#line 708 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 14: // meta_shared_tokens: SOURCE
#line 227 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.MetaQueryKeywordType_) = MetaQueryKeyword::SOURCE;
}
#line 716 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 15: // sql_query: create_table_query
#line 233 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.SqlQueryType_) = (yystack_[0].value.CreateStatementType);
}
#line 724 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 16: // sql_query: drop_table_query
#line 237 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.SqlQueryType_) = (yystack_[0].value.DropStatementType);
}
#line 732 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 17: // sql_query: insert_query
#line 241 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.SqlQueryType_) = (yystack_[0].value.InsertStatementType);
}
#line 740 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 18: // sql_query: select_query
#line 245 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.SqlQueryType_) = (yystack_[0].value.SelectStatementType);
}
#line 748 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 19: // sql_query: update_query
#line 249 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.SqlQueryType_) = (yystack_[0].value.UpdateStatementType);
}
#line 756 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 20: // sql_query: delete_query
#line 253 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.SqlQueryType_) = (yystack_[0].value.DeleteStatementType);
}
#line 764 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 21: // create_table_query: CREATE TABLE IDENTIFIER OPEN_B column_definition_list CLOSE_B
#line 259 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.CreateStatementType) = new CreateStatement((yystack_[3].value.stringval),columnDefinitionLst);
columnDefinitionLst.clear();
}
#line 773 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 22: // column_definition_list: column_definition
#line 266 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
columnDefinitionLst.push_back((yystack_[0].value.ColumnDefinitionType));
}
#line 781 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 23: // column_definition_list: column_definition_list COMMA column_definition
#line 270 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
columnDefinitionLst.push_back((yystack_[0].value.ColumnDefinitionType));}
#line 788 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 24: // column_definition: IDENTIFIER data_type constraint
#line 275 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ColumnDefinitionType) = new ColumnDefinition((yystack_[2].value.stringval),(yystack_[1].value.DataType_),(yystack_[0].value.ConstraintType_));
}
#line 796 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 25: // data_type: TEXT
#line 280 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
       {
(yylhs.value.DataType_) = DataType::TEXT;
}
#line 804 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 26: // data_type: INT
#line 283 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
      {
(yylhs.value.DataType_) = DataType::INT;
}
#line 812 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 27: // data_type: REAL
#line 287 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.DataType_) = DataType::REAL;
}
#line 820 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 28: // constraint: %empty
#line 292 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
         {
(yylhs.value.ConstraintType_) = nullptr;
}
#line 828 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 29: // constraint: PRIMARY KEY
#line 296 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConstraintType_) = new Constraint(ConstraintType::PRIMARY);
}
#line 836 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 30: // constraint: NOT NULL_
#line 300 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConstraintType_) = new Constraint(ConstraintType::NOT_NULL);
}
#line 844 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 31: // constraint: UNIQUE
#line 304 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConstraintType_)=new Constraint(ConstraintType::UNIQUE);
}
#line 852 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 32: // constraint: AUTOINCREMENT
#line 309 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConstraintType_)=new Constraint(ConstraintType::AUTOINCREMENT);
}
#line 860 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 33: // constraint: DEFAULT value
#line 313 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConstraintType_)=new Constraint(ConstraintType::DEFAULT,new std::string(*(yystack_[0].value.stringval)));
}
#line 868 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 34: // drop_table_query: DROP TABLE IDENTIFIER
#line 319 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.DropStatementType) = new DropStatement((yystack_[0].value.stringval));
}
#line 876 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 35: // insert_query: INSERT INTO IDENTIFIER column_inserted VALUES OPEN_B values_list CLOSE_B
#line 325 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.InsertStatementType) = new InsertStatement((yystack_[5].value.stringval),columnInsertedLst,valuesInsertedLst);
}
#line 884 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 38: // columns_comma_seperated_list: IDENTIFIER
#line 335 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
columnInsertedLst.push_back((yystack_[0].value.stringval));
columnSelectedLst.push_back((yystack_[0].value.stringval));
 }
#line 893 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 39: // columns_comma_seperated_list: columns_comma_seperated_list COMMA IDENTIFIER
#line 340 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
columnInsertedLst.push_back((yystack_[0].value.stringval));
columnSelectedLst.push_back((yystack_[0].value.stringval));
 }
#line 902 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 40: // values_list: value
#line 347 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
valuesInsertedLst.push_back((yystack_[0].value.stringval));
}
#line 910 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 41: // values_list: values_list COMMA value
#line 351 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
valuesInsertedLst.push_back((yystack_[0].value.stringval));
}
#line 918 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 42: // update_query: UPDATE IDENTIFIER SET comma_sperated_assignments conditional_where
#line 357 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.UpdateStatementType) = new UpdateStatement((yystack_[3].value.stringval),updatekeyValMap,(yystack_[0].value.ConditionType_));
}
#line 926 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 43: // select_query: SELECT select_list FROM IDENTIFIER conditional_where optional_order
#line 363 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
if(*(yystack_[4].value.CharType) == '*'){
(yylhs.value.SelectStatementType) = new SelectStatement((yystack_[2].value.stringval),(yystack_[1].value.ConditionType_),columnOrderedLst,true);
}else{
(yylhs.value.SelectStatementType) = new SelectStatement((yystack_[2].value.stringval),(yystack_[1].value.ConditionType_),columnSelectedLst,columnOrderedLst);
}
(yystack_[4].value.CharType) = nullptr;
}
#line 939 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 46: // order_by_col: IDENTIFIER optional_order_type
#line 378 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.OrderByColumnType) = new OrderByColumn((yystack_[0].value.OrderByType_),(yystack_[1].value.stringval));
}
#line 947 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 47: // order_by_col_list: order_by_col
#line 384 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
columnOrderedLst.push_back((yystack_[0].value.OrderByColumnType));
}
#line 955 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 48: // order_by_col_list: order_by_col_list COMMA order_by_col
#line 388 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
columnOrderedLst.push_back((yystack_[0].value.OrderByColumnType));
}
#line 963 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 49: // optional_order_type: %empty
#line 394 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
}
#line 970 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 50: // optional_order_type: ASC
#line 397 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.OrderByType_) = OrderByType::ASC;
}
#line 978 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 51: // optional_order_type: DESC
#line 401 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.OrderByType_) = OrderByType::ASC;
}
#line 986 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 52: // select_list: ASTREISK
#line 407 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.CharType) = new char('*');
}
#line 994 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 53: // select_list: columns_comma_seperated_list
#line 411 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.CharType) = nullptr;
}
#line 1002 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 54: // delete_query: DELETE FROM IDENTIFIER conditional_where
#line 417 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.DeleteStatementType) = new DeleteStatement((yystack_[1].value.stringval),(yystack_[0].value.ConditionType_));
}
#line 1010 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 55: // conditional_where: %empty
#line 423 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConditionType_) = nullptr;
}
#line 1018 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 56: // conditional_where: WHERE conditional_assignments
#line 427 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConditionType_) = (yystack_[0].value.ConditionType_);
}
#line 1026 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 57: // conditional_assignments: conditional_assignment
#line 433 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConditionType_) = (yystack_[0].value.ConditionType_);
}
#line 1034 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 58: // conditional_assignments: conditional_assignment and_or_operator conditional_assignments
#line 437 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConditionType_)  = new MultiCondition((yystack_[2].value.ConditionType_),(yystack_[0].value.ConditionType_),(yystack_[1].value.AND_ORType_));
}
#line 1042 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 59: // conditional_assignment: IDENTIFIER conditional_operator value
#line 443 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.ConditionType_) = new Condition((yystack_[2].value.stringval),(yystack_[0].value.stringval),(yystack_[1].value.Condition_OperatorType_));
}
#line 1050 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 60: // conditional_operator: EQUAL
#line 449 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.Condition_OperatorType_) = Condition_Operator::EQUAL;
}
#line 1058 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 61: // conditional_operator: NOT_EQUAL
#line 453 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.Condition_OperatorType_) = Condition_Operator::NOT_EQUAL;
}
#line 1066 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 62: // conditional_operator: GREATER
#line 457 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.Condition_OperatorType_) = Condition_Operator::GREATER_THAN;
}
#line 1074 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 63: // conditional_operator: LOWER
#line 461 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.Condition_OperatorType_) = Condition_Operator::LOWER_THAN;
}
#line 1082 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 64: // conditional_operator: LOWER_OR_EQUAL
#line 465 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.Condition_OperatorType_) = Condition_Operator::LOWER_THAN_OR_EQUAL;
}
#line 1090 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 65: // conditional_operator: GREATER_OR_EQUAL
#line 469 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.Condition_OperatorType_) = Condition_Operator::GREATER_THAN_OR_EQUAL;
}
#line 1098 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 66: // and_or_operator: AND
#line 475 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.AND_ORType_) = AND_OR::AND;
}
#line 1106 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 67: // and_or_operator: OR
#line 479 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.AND_ORType_) = AND_OR::OR;
}
#line 1114 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 68: // comma_sperated_assignments: assignment
#line 485 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
updatekeyValMap.push_back((yystack_[0].value.KeyValueAssignmentType_));
}
#line 1122 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 69: // comma_sperated_assignments: comma_sperated_assignments COMMA assignment
#line 489 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
updatekeyValMap.push_back((yystack_[0].value.KeyValueAssignmentType_));
}
#line 1130 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 70: // assignment: IDENTIFIER EQUAL value
#line 495 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.KeyValueAssignmentType_) = new KeyValueAssignment((yystack_[2].value.stringval),(yystack_[0].value.stringval));
}
#line 1138 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 71: // value: STRING
#line 501 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.stringval) = new std::string(*(yystack_[0].value.stringval));
}
#line 1146 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 72: // value: INTEGER
#line 505 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.stringval) = new std::string(std::to_string((yystack_[0].value.intval)));
}
#line 1154 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;

  case 73: // value: DOUBLE
#line 509 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
{
(yylhs.value.stringval) = new std::string(std::to_string((yystack_[0].value.doubleval)));
}
#line 1162 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"
    break;


#line 1166 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -72;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -72,    10,     0,   -72,   -72,    11,   -21,   -20,    -5,    21,
      12,   -31,   -72,   -72,    17,   -72,   -72,   -72,   -72,   -72,
     -72,     4,   -72,   -72,     9,    27,    14,    20,    16,    18,
     -72,   -72,   -72,   -72,   -72,   -72,    19,   -72,    57,    22,
      23,    60,    24,   -72,    35,   -72,    25,   -72,    35,    26,
      34,    52,   -30,   -72,    29,   -72,    42,    -4,   -72,    43,
      -2,    71,     8,    24,   -72,     7,   -72,    -7,   -72,   -72,
     -72,    -3,   -72,    25,    44,   -72,   -72,     8,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     8,
     -72,   -72,    29,    65,    64,   -72,   -72,     8,   -72,   -72,
      36,    -1,   -72,   -72,   -72,   -72,   -72,   -72,     3,   -72,
      31,   -72,     8,   -72,   -72,   -72,    36,   -72,   -72
  };

  const signed char
  Parser::yydefact_[] =
  {
       3,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     0,    15,    16,    17,    19,    18,
      20,     0,    52,    38,    53,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     7,     8,     9,     6,     0,     0,
       0,    36,     0,    34,    55,    10,     0,    39,    55,     0,
       0,     0,    55,    68,     0,    54,     0,     0,    22,    44,
       0,     0,     0,     0,    42,     0,    56,    57,    26,    27,
      25,    28,    21,     0,     0,    43,    37,     0,    72,    71,
      73,    70,    69,    60,    61,    62,    63,    64,    65,     0,
      66,    67,     0,     0,     0,    32,    31,     0,    24,    23,
       0,     0,    40,    59,    58,    29,    30,    33,    49,    47,
      45,    35,     0,    50,    51,    46,     0,    41,    48
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,    13,   -72,   -72,   -72,   -72,   -72,    33,   -72,   -72,
     -72,   -72,   -33,   -72,   -72,   -72,   -72,   -40,    -8,   -72,
     -72,   -72,   -72,    28,   -71
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,    12,    13,    34,    35,    36,    14,    15,
      57,    58,    71,    98,    16,    17,    50,    24,   101,    18,
      19,    75,   109,   110,   115,    25,    20,    55,    66,    67,
      89,    92,    52,    53,    81
  };

  const signed char
  Parser::yytable_[] =
  {
       4,    54,    72,     5,    76,   111,   102,    22,    59,    93,
       3,    94,    64,    95,    96,    21,    97,    26,   103,    63,
      30,    31,    32,    33,    23,    28,   107,     6,    83,    84,
      85,    86,    87,    88,    90,    91,     7,   113,   114,     8,
      27,   117,    29,     9,    10,    73,    37,    39,   112,    38,
      11,    68,    69,    70,    78,    79,    80,    40,    39,    41,
      42,    43,    46,    44,    45,    49,    54,    47,    48,    51,
      56,    23,    61,    62,    65,    74,    77,   100,   105,   106,
     116,   108,    60,   118,   104,     0,    99,     0,     0,     0,
       0,    82
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,    31,     6,     3,     6,     6,    77,    28,    48,    12,
       0,    14,    52,    16,    17,     4,    19,    37,    89,    49,
      51,    52,    53,    54,    45,     4,    97,    27,    21,    22,
      23,    24,    25,    26,    41,    42,    36,    34,    35,    39,
      45,   112,    30,    43,    44,    49,    29,    49,    49,    45,
      50,     9,    10,    11,    46,    47,    48,    30,    49,    45,
      40,    45,     5,    45,    45,     5,    31,    45,    45,    45,
      45,    45,    38,    21,    45,    32,     5,    33,    13,    15,
      49,    45,    49,   116,    92,    -1,    73,    -1,    -1,    -1,
      -1,    63
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    57,    58,     0,     0,     3,    27,    36,    39,    43,
      44,    50,    59,    60,    64,    65,    70,    71,    75,    76,
      82,     4,    28,    45,    73,    81,    37,    45,     4,    30,
      51,    52,    53,    54,    61,    62,    63,    29,    45,    49,
      30,    45,    40,    45,    45,    45,     5,    45,    45,     5,
      72,    45,    88,    89,    31,    83,    45,    66,    67,    83,
      73,    38,    21,    49,    83,    45,    84,    85,     9,    10,
      11,    68,     6,    49,    32,    77,     6,     5,    46,    47,
      48,    90,    89,    21,    22,    23,    24,    25,    26,    86,
      41,    42,    87,    12,    14,    16,    17,    19,    69,    67,
      33,    74,    90,    90,    84,    13,    15,    90,    45,    78,
      79,     6,    49,    34,    35,    80,    49,    90,    78
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    56,    57,    58,    58,    59,    59,    60,    60,    61,
      62,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    65,    66,    66,    67,    68,    68,    68,    69,    69,
      69,    69,    69,    69,    70,    71,    72,    72,    73,    73,
      74,    74,    75,    76,    77,    77,    78,    79,    79,    80,
      80,    80,    81,    81,    82,    83,    83,    84,    84,    85,
      86,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      89,    90,    90,    90
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,     1,     2,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     1,     3,     3,     1,     1,     1,     0,     2,
       2,     1,     1,     2,     3,     8,     0,     3,     1,     3,
       1,     3,     5,     6,     0,     3,     2,     1,     3,     0,
       1,     1,     1,     1,     4,     0,     2,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"END OF FILE\"", "error", "\"invalid token\"", "CREATE", "TABLE",
  "OPEN_B", "CLOSE_B", "DOUBLE_Q", "SINGLE_Q", "INT", "REAL", "TEXT",
  "PRIMARY", "KEY", "NOT", "NULL_", "AUTOINCREMENT", "UNIQUE", "INNER",
  "DEFAULT", "JOIN", "EQUAL", "NOT_EQUAL", "GREATER", "LOWER",
  "LOWER_OR_EQUAL", "GREATER_OR_EQUAL", "SELECT", "ASTREISK", "SEMICOLN",
  "FROM", "WHERE", "ORDER", "BY", "ASC", "DESC", "INSERT", "INTO",
  "VALUES", "UPDATE", "SET", "AND", "OR", "DROP", "DELETE", "IDENTIFIER",
  "INTEGER", "STRING", "DOUBLE", "COMMA", "DOT", "SCHEMA", "TABLES",
  "EXIT", "SOURCE", "UNDEFIEND", "$accept", "S", "queries", "query",
  "meta_query", "no_param_meta", "one_param_meta", "meta_shared_tokens",
  "sql_query", "create_table_query", "column_definition_list",
  "column_definition", "data_type", "constraint", "drop_table_query",
  "insert_query", "column_inserted", "columns_comma_seperated_list",
  "values_list", "update_query", "select_query", "optional_order",
  "order_by_col", "order_by_col_list", "optional_order_type",
  "select_list", "delete_query", "conditional_where",
  "conditional_assignments", "conditional_assignment",
  "conditional_operator", "and_or_operator", "comma_sperated_assignments",
  "assignment", "value", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   166,   166,   169,   170,   176,   180,   192,   196,   202,
     208,   214,   218,   222,   226,   232,   236,   240,   244,   248,
     252,   258,   265,   269,   274,   280,   283,   286,   292,   295,
     299,   303,   308,   312,   318,   324,   330,   331,   334,   339,
     346,   350,   356,   362,   373,   374,   377,   383,   387,   393,
     396,   400,   406,   410,   416,   422,   426,   432,   436,   442,
     448,   452,   456,   460,   464,   468,   474,   478,   484,   488,
     494,   500,   504,   508
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
    };
    // Last valid token kind.
    const int code_max = 310;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 4 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"
} } // core::compiler
#line 1614 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.cpp"

#line 513 "/home/mohamed/Documents/projects/sqliter/src/core/compiler/parser.y"

void core::compiler::Parser::error(const location_type& loc,const std::string& msg){
 	throw exceptions::ParserException(loc,msg);
}
