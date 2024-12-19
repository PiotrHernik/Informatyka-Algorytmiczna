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
#line 30 "parser.ypp"

#include "scanner.hpp"


yy::Parser::symbol_type yylex(yy::Scanner &scanner) {
    return scanner.scan();
}

#line 55 "parser.cpp"


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

namespace yy {
#line 147 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (yy::Scanner &scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



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
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUM: // NUM
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.YY_MOVE_OR_COPY< std::unique_ptr<Identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_command: // command
        value.YY_MOVE_OR_COPY< std::unique_ptr<Node> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_value: // value
        value.YY_MOVE_OR_COPY< std::unique_ptr<Value> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUM: // NUM
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< std::unique_ptr<Identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_command: // command
        value.move< std::unique_ptr<Node> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_value: // value
        value.move< std::unique_ptr<Value> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUM: // NUM
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
        value.copy< std::unique_ptr<Identifier> > (that.value);
        break;

      case symbol_kind::S_command: // command
        value.copy< std::unique_ptr<Node> > (that.value);
        break;

      case symbol_kind::S_value: // value
        value.copy< std::unique_ptr<Value> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUM: // NUM
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< std::unique_ptr<Identifier> > (that.value);
        break;

      case symbol_kind::S_command: // command
        value.move< std::unique_ptr<Node> > (that.value);
        break;

      case symbol_kind::S_value: // value
        value.move< std::unique_ptr<Value> > (that.value);
        break;

      default:
        break;
    }

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

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

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
            symbol_type yylookahead (yylex (scanner));
            yyla.move (yylookahead);
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
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_NUM: // NUM
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_identifier: // identifier
        yylhs.value.emplace< std::unique_ptr<Identifier> > ();
        break;

      case symbol_kind::S_command: // command
        yylhs.value.emplace< std::unique_ptr<Node> > ();
        break;

      case symbol_kind::S_value: // value
        yylhs.value.emplace< std::unique_ptr<Value> > ();
        break;

      default:
        break;
    }


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
  case 6: // main: KW_PROGRAM KW_IS declarations KW_BEGIN commands KW_END
#line 104 "parser.ypp"
                                                               { std::cout << "KW_PROGRAM KW_IS declarations KW_BEGIN commands KW_END" << std::endl; }
#line 652 "parser.cpp"
    break;

  case 7: // main: KW_PROGRAM KW_IS KW_BEGIN commands KW_END
#line 105 "parser.ypp"
                                                    { std::cout << "KW_PROGRAM KW_IS KW_BEGIN commands KW_END" << std::endl; }
#line 658 "parser.cpp"
    break;

  case 8: // commands: commands command
#line 108 "parser.ypp"
                         { std::cout << "commands command" << std::endl; }
#line 664 "parser.cpp"
    break;

  case 9: // commands: command
#line 109 "parser.ypp"
                  { std::cout << "command" << std::endl; }
#line 670 "parser.cpp"
    break;

  case 10: // command: identifier ASSIGN expression SEMICOLON
#line 112 "parser.ypp"
                                               { std::cout << "identifier ASSIGN expression;" << std::endl; }
#line 676 "parser.cpp"
    break;

  case 11: // command: KW_IF condition KW_THEN commands KW_ELSE commands KW_ENDIF
#line 113 "parser.ypp"
                                                                     { std::cout << "KW_IF condition KW_THEN commands KW_ELSE commands KW_ENDIF" << std::endl; }
#line 682 "parser.cpp"
    break;

  case 12: // command: KW_IF condition KW_THEN commands KW_ENDIF
#line 114 "parser.ypp"
                                                    { std::cout << "KW_IF condition KW_THEN commands KW_ENDIF" << std::endl; }
#line 688 "parser.cpp"
    break;

  case 13: // command: KW_WHILE condition KW_DO commands KW_ENDWHILE
#line 115 "parser.ypp"
                                                        { std::cout << "KW_WHILE condition KW_DO commands KW_ENDWHILE" << std::endl; }
#line 694 "parser.cpp"
    break;

  case 14: // command: KW_REPEAT commands KW_UNTIL condition SEMICOLON
#line 116 "parser.ypp"
                                                          { std::cout << "KW_REPEAT commands KW_UNTIL condition;" << std::endl; }
#line 700 "parser.cpp"
    break;

  case 15: // command: KW_FOR PIDENTIFIER KW_FROM value KW_TO value KW_DO commands KW_ENDFOR
#line 117 "parser.ypp"
                                                                                { std::cout << "KW_FOR PIDENTIFIER KW_FROM value KW_TO value KW_DO commands KW_ENDFOR" << std::endl; }
#line 706 "parser.cpp"
    break;

  case 16: // command: KW_FOR PIDENTIFIER KW_FROM value KW_DOWNTO value KW_DO commands KW_ENDFOR
#line 118 "parser.ypp"
                                                                                    { std::cout << "KW_FOR PIDENTIFIER KW_FROM value KW_DOWNTO value KW_DO commands KW_ENDFOR" << std::endl; }
#line 712 "parser.cpp"
    break;

  case 17: // command: proc_call SEMICOLON
#line 119 "parser.ypp"
                              { std::cout << "proc_call;" << std::endl; }
#line 718 "parser.cpp"
    break;

  case 18: // command: KW_READ identifier SEMICOLON
#line 120 "parser.ypp"
                                       { }
#line 724 "parser.cpp"
    break;

  case 19: // command: KW_WRITE value SEMICOLON
#line 121 "parser.ypp"
                                   { std::cout << "KW_WRITE value;" << std::endl; }
#line 730 "parser.cpp"
    break;

  case 20: // proc_head: PIDENTIFIER LPRNT args_decl RPRNT
#line 124 "parser.ypp"
                                          { std::cout << "PIDENTIFIER(args_decl)" << std::endl; }
#line 736 "parser.cpp"
    break;

  case 21: // proc_call: PIDENTIFIER LPRNT args RPRNT
#line 127 "parser.ypp"
                                     { std::cout << "PIDENTIFIER(args)" << std::endl; }
#line 742 "parser.cpp"
    break;

  case 22: // declarations: declarations COMMA PIDENTIFIER
#line 130 "parser.ypp"
                                       { std::cout << "declarations, PIDENTIFIER" << std::endl; }
#line 748 "parser.cpp"
    break;

  case 23: // declarations: declarations COMMA PIDENTIFIER LBRACKET NUM COLON NUM RBRACKET
#line 131 "parser.ypp"
                                                                         { std::cout << "declarations, PIDENTIFIER[NUM:NUM]" << std::endl; }
#line 754 "parser.cpp"
    break;

  case 24: // declarations: PIDENTIFIER
#line 132 "parser.ypp"
                      { std::cout << "pidentifier1" << std::endl; }
#line 760 "parser.cpp"
    break;

  case 25: // declarations: PIDENTIFIER LBRACKET NUM COLON NUM RBRACKET
#line 133 "parser.ypp"
                                                      { std::cout << "PIDENTIFIER[NUM:NUM]" << std::endl; }
#line 766 "parser.cpp"
    break;

  case 26: // args_decl: args_decl COMMA PIDENTIFIER
#line 136 "parser.ypp"
                                    { std::cout << "args_decl, PIDENTIFIER" << std::endl; }
#line 772 "parser.cpp"
    break;

  case 27: // args_decl: args_decl COMMA KW_T PIDENTIFIER
#line 137 "parser.ypp"
                                           { std::cout << "args_decl, T PIDENTIFIER" << std::endl; }
#line 778 "parser.cpp"
    break;

  case 28: // args_decl: PIDENTIFIER
#line 138 "parser.ypp"
                      { std::cout << "pidentifier2" << std::endl; }
#line 784 "parser.cpp"
    break;

  case 29: // args_decl: KW_T PIDENTIFIER
#line 139 "parser.ypp"
                           { std::cout << "T PIDENTIFIER" << std::endl; }
#line 790 "parser.cpp"
    break;

  case 30: // args: args COMMA PIDENTIFIER
#line 142 "parser.ypp"
                               { std::cout << "args, PIDENTIFIER" << std::endl; }
#line 796 "parser.cpp"
    break;

  case 31: // args: PIDENTIFIER
#line 143 "parser.ypp"
                      { std::cout << "pidentifier3" << std::endl; }
#line 802 "parser.cpp"
    break;

  case 32: // expression: value
#line 146 "parser.ypp"
              { std::cout << "value" << std::endl; }
#line 808 "parser.cpp"
    break;

  case 33: // expression: value PLUS value
#line 147 "parser.ypp"
                           { std::cout << "value + value" << std::endl; }
#line 814 "parser.cpp"
    break;

  case 34: // expression: value MINUS value
#line 148 "parser.ypp"
                            { std::cout << "value - value" << std::endl; }
#line 820 "parser.cpp"
    break;

  case 35: // expression: value MULT value
#line 149 "parser.ypp"
                           { std::cout << "value * value" << std::endl; }
#line 826 "parser.cpp"
    break;

  case 36: // expression: value DIV value
#line 150 "parser.ypp"
                          { std::cout << "value / value" << std::endl; }
#line 832 "parser.cpp"
    break;

  case 37: // expression: value MOD value
#line 151 "parser.ypp"
                          { std::cout << "value % value" << std::endl; }
#line 838 "parser.cpp"
    break;

  case 38: // condition: value EQUAL value
#line 154 "parser.ypp"
                          { std::cout << "value == value" << std::endl; }
#line 844 "parser.cpp"
    break;

  case 39: // condition: value NEQUAL value
#line 155 "parser.ypp"
                             { std::cout << "value != value" << std::endl; }
#line 850 "parser.cpp"
    break;

  case 40: // condition: value MORE value
#line 156 "parser.ypp"
                           { std::cout << "value > value" << std::endl; }
#line 856 "parser.cpp"
    break;

  case 41: // condition: value LESS value
#line 157 "parser.ypp"
                           { std::cout << "value < value" << std::endl; }
#line 862 "parser.cpp"
    break;

  case 42: // condition: value MOREOREQUAL value
#line 158 "parser.ypp"
                                  { std::cout << "value >= value" << std::endl; }
#line 868 "parser.cpp"
    break;

  case 43: // condition: value LESSOREQUAL value
#line 159 "parser.ypp"
                                  { std::cout << "value <= value" << std::endl; }
#line 874 "parser.cpp"
    break;

  case 44: // value: NUM
#line 162 "parser.ypp"
            { yylhs.value.as < std::unique_ptr<Value> > () = std::make_unique<Value>(yystack_[0].value.as < long long > (), ValueEnum::NUM); }
#line 880 "parser.cpp"
    break;

  case 45: // value: identifier
#line 163 "parser.ypp"
                     { yylhs.value.as < std::unique_ptr<Value> > () = std::make_unique<Value>(std::move(yystack_[0].value.as < std::unique_ptr<Identifier> > ()), ValueEnum::ID); }
#line 886 "parser.cpp"
    break;

  case 46: // identifier: PIDENTIFIER
#line 166 "parser.ypp"
                    { yylhs.value.as < std::unique_ptr<Identifier> > () = std::make_unique<Identifier>(yystack_[0].value.as < std::string > (), IdentifierEnum::PID); }
#line 892 "parser.cpp"
    break;

  case 47: // identifier: PIDENTIFIER LBRACKET PIDENTIFIER RBRACKET
#line 167 "parser.ypp"
                                                    {  yylhs.value.as < std::unique_ptr<Identifier> > () = std::make_unique<Identifier>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::string > (), IdentifierEnum::PIDTPID); }
#line 898 "parser.cpp"
    break;

  case 48: // identifier: PIDENTIFIER LBRACKET NUM RBRACKET
#line 168 "parser.ypp"
                                            {  yylhs.value.as < std::unique_ptr<Identifier> > () = std::make_unique<Identifier>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < long long > (), IdentifierEnum::PIDT); }
#line 904 "parser.cpp"
    break;


#line 908 "parser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
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
      yy_lac_discard_ ("error recovery");
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

  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "KW_IF", "KW_ELSE", "NEWLINE",
  "KW_PROCEDURE", "KW_IS", "KW_BEGIN", "KW_END", "KW_PROGRAM", "KW_THEN",
  "KW_ENDIF", "KW_WHILE", "KW_DO", "KW_ENDWHILE", "KW_REPEAT", "KW_UNTIL",
  "KW_FOR", "KW_FROM", "KW_ENDFOR", "KW_DOWNTO", "KW_READ", "KW_WRITE",
  "KW_TO", "KW_T", "EQUAL", "NEQUAL", "LESS", "MORE", "LESSOREQUAL",
  "MOREOREQUAL", "ASSIGN", "SEMICOLON", "COLON", "COMMA", "LPRNT", "RPRNT",
  "LBRACKET", "RBRACKET", "PLUS", "MINUS", "MULT", "DIV", "MOD", "NUM",
  "PIDENTIFIER", "$accept", "program_all", "procedures", "main",
  "commands", "command", "proc_head", "proc_call", "declarations",
  "args_decl", "args", "expression", "condition", "value", "identifier", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  Parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  Parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  Parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -40;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -40,    17,    51,   -40,   -39,    16,   -40,    -8,    45,     1,
     -22,     2,   230,    22,    -6,    18,   -40,   -29,   230,     7,
      28,    28,   230,    29,    36,    28,   -20,    40,   -40,    52,
      59,    48,   230,    50,   -40,    25,   -40,    89,   230,   -40,
      56,    86,   132,   -40,    85,    23,    81,    68,    73,    64,
      42,   -40,   -40,   -40,    28,    84,   134,    82,    75,   -40,
     -40,   169,   230,    28,    28,    28,    28,    28,    28,   230,
      28,    28,   -40,   -40,   -40,    35,    83,    87,    90,    98,
      99,   -40,   100,   -40,   -40,     9,   -40,   -40,   -40,   -40,
     -40,   -40,   180,    94,    44,    88,   -40,   -40,   -40,   -40,
      28,    28,    28,    28,    28,   107,   114,   230,   -40,   -40,
     -40,    28,    28,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     104,   194,   137,   139,   115,   -40,   230,   230,   -40,   205,
     216,   -40,   -40
  };

  const signed char
  Parser::yydefact_[] =
  {
       5,     0,     0,     1,     0,     0,     2,     0,     0,     0,
       0,     0,     0,    24,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     9,     0,
       0,     0,     0,     0,    29,     0,    20,     0,     0,    44,
      46,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     7,     8,    17,     0,     0,     0,    22,     0,    26,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    31,     0,     0,     0,     0,    32,
       0,     6,     0,    27,     3,     0,    38,    39,    41,    40,
      43,    42,     0,     0,     0,     0,    21,    48,    47,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
      14,     0,     0,    30,    33,    34,    35,    36,    37,    25,
       0,     0,     0,     0,     0,    11,     0,     0,    23,     0,
       0,    16,    15
  };

  const short
  Parser::yypgoto_[] =
  {
     -40,   -40,   -40,   -40,   -18,   -26,   -40,   -40,   144,   -40,
     -40,   -40,   -16,    65,    13
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     6,    27,    28,     8,    29,    14,    17,
      75,    78,    41,    42,    30
  };

  const unsigned char
  Parser::yytable_[] =
  {
      37,    52,    32,    15,    45,    44,    35,     7,    36,    12,
      18,    52,    20,   107,    56,    38,    49,     3,    50,    52,
      61,   108,    21,     9,    16,    22,    20,    23,    10,    33,
      52,    24,    25,    43,    43,    52,    21,    47,    43,    22,
      70,    23,    33,    20,    85,    24,    25,    13,    13,    51,
      58,    92,    11,    21,    93,    26,    22,     4,    23,    52,
      31,     5,    24,    25,    34,   111,    52,    43,   112,    26,
      95,    59,    96,    39,    40,    46,    43,    43,    43,    43,
      43,    43,    40,    43,    43,    53,    26,    76,    77,   121,
      48,    54,    20,    55,    50,    52,    57,    62,    60,    69,
      71,    72,    21,    52,    52,    22,    73,    23,   129,   130,
      74,    24,    25,    43,    43,    43,    43,    43,    80,    79,
      82,    83,    97,    99,    43,    43,    98,   110,    86,    87,
      88,    89,    90,    91,   113,    26,    94,    20,   100,   101,
     102,   103,   104,    81,   105,   106,   119,    21,   120,   124,
      22,   126,    23,   127,   128,    19,    24,    25,    63,    64,
      65,    66,    67,    68,     0,   114,   115,   116,   117,   118,
       0,     0,    20,     0,     0,     0,   122,   123,    84,     0,
      26,     0,    21,    20,     0,    22,     0,    23,     0,     0,
       0,    24,    25,    21,     0,   109,    22,    20,    23,     0,
       0,     0,    24,    25,     0,     0,   125,    21,    20,     0,
      22,     0,    23,     0,     0,    26,    24,    25,    21,    20,
       0,    22,     0,    23,     0,   131,    26,    24,    25,    21,
       0,     0,    22,    20,    23,     0,   132,     0,    24,    25,
      26,     0,     0,    21,     0,     0,    22,     0,    23,     0,
       0,    26,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26
  };

  const short
  Parser::yycheck_[] =
  {
      18,    27,     8,    25,    22,    21,    35,    46,    37,     8,
       8,    37,     3,     4,    32,     8,    36,     0,    38,    45,
      38,    12,    13,     7,    46,    16,     3,    18,    36,    35,
      56,    22,    23,    20,    21,    61,    13,    24,    25,    16,
      17,    18,    35,     3,    62,    22,    23,    46,    46,     9,
      25,    69,     7,    13,    70,    46,    16,     6,    18,    85,
      38,    10,    22,    23,    46,    21,    92,    54,    24,    46,
      35,    46,    37,    45,    46,    46,    63,    64,    65,    66,
      67,    68,    46,    70,    71,    33,    46,    45,    46,   107,
      25,    32,     3,    45,    38,   121,    46,    11,     9,    14,
      19,    33,    13,   129,   130,    16,    33,    18,   126,   127,
      46,    22,    23,   100,   101,   102,   103,   104,    34,    54,
      38,    46,    39,    33,   111,   112,    39,    33,    63,    64,
      65,    66,    67,    68,    46,    46,    71,     3,    40,    41,
      42,    43,    44,     9,    45,    45,    39,    13,    34,    45,
      16,    14,    18,    14,    39,    11,    22,    23,    26,    27,
      28,    29,    30,    31,    -1,   100,   101,   102,   103,   104,
      -1,    -1,     3,    -1,    -1,    -1,   111,   112,     9,    -1,
      46,    -1,    13,     3,    -1,    16,    -1,    18,    -1,    -1,
      -1,    22,    23,    13,    -1,    15,    16,     3,    18,    -1,
      -1,    -1,    22,    23,    -1,    -1,    12,    13,     3,    -1,
      16,    -1,    18,    -1,    -1,    46,    22,    23,    13,     3,
      -1,    16,    -1,    18,    -1,    20,    46,    22,    23,    13,
      -1,    -1,    16,     3,    18,    -1,    20,    -1,    22,    23,
      46,    -1,    -1,    13,    -1,    -1,    16,    -1,    18,    -1,
      -1,    46,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    48,    49,     0,     6,    10,    50,    46,    53,     7,
      36,     7,     8,    46,    55,    25,    46,    56,     8,    55,
       3,    13,    16,    18,    22,    23,    46,    51,    52,    54,
      61,    38,     8,    35,    46,    35,    37,    51,     8,    45,
      46,    59,    60,    61,    59,    51,    46,    61,    60,    36,
      38,     9,    52,    33,    32,    45,    51,    46,    25,    46,
       9,    51,    11,    26,    27,    28,    29,    30,    31,    14,
      17,    19,    33,    33,    46,    57,    45,    46,    58,    60,
      34,     9,    38,    46,     9,    51,    60,    60,    60,    60,
      60,    60,    51,    59,    60,    35,    37,    39,    39,    33,
      40,    41,    42,    43,    44,    45,    45,     4,    12,    15,
      33,    21,    24,    46,    60,    60,    60,    60,    60,    39,
      34,    51,    60,    60,    45,    12,    14,    14,    39,    51,
      51,    20,    20
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    47,    48,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    54,    55,    55,    55,    55,    56,    56,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    61
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     8,     7,     0,     6,     5,     2,     1,
       4,     7,     5,     5,     5,     9,     9,     2,     3,     3,
       4,     4,     3,     8,     1,     6,     3,     4,     1,     2,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     4
  };




#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    95,    95,    98,    99,   100,   104,   105,   108,   109,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     124,   127,   130,   131,   132,   133,   136,   137,   138,   139,
     142,   143,   146,   147,   148,   149,   150,   151,   154,   155,
     156,   157,   158,   159,   162,   163,   166,   167,   168
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


} // yy
#line 1574 "parser.cpp"

#line 171 "parser.ypp"


void yy::Parser::error(const location_type& loc, const std::string& msg)
{
    std::cout << "ERROR at "<< loc << ", message: " << msg << std::endl;
}
