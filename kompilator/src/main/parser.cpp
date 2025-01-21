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
#line 31 "main/parser.ypp"

#include "scanner.hpp"


yy::Parser::symbol_type yylex(yy::Scanner &scanner) {
    return scanner.scan();
}

#line 55 "main/parser.cpp"


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
#line 147 "main/parser.cpp"

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
      case symbol_kind::S_number: // number
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_command: // command
        value.YY_MOVE_OR_COPY< std::shared_ptr<Command> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.YY_MOVE_OR_COPY< std::shared_ptr<Condition> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.YY_MOVE_OR_COPY< std::shared_ptr<Identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_main: // main
        value.YY_MOVE_OR_COPY< std::shared_ptr<Main> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc_call: // proc_call
        value.YY_MOVE_OR_COPY< std::shared_ptr<ProcCall> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc_head: // proc_head
        value.YY_MOVE_OR_COPY< std::shared_ptr<ProcHead> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_value: // value
        value.YY_MOVE_OR_COPY< std::shared_ptr<Value> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args: // args
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Args>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args_decl: // args_decl
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ArgsDeclaration>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_commands: // commands
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Command>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Declaration>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedures: // procedures
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<Procedure>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_number: // number
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_command: // command
        value.move< std::shared_ptr<Command> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.move< std::shared_ptr<Condition> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< std::shared_ptr<Identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_main: // main
        value.move< std::shared_ptr<Main> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc_call: // proc_call
        value.move< std::shared_ptr<ProcCall> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc_head: // proc_head
        value.move< std::shared_ptr<ProcHead> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_value: // value
        value.move< std::shared_ptr<Value> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<std::shared_ptr<Args>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args_decl: // args_decl
        value.move< std::vector<std::shared_ptr<ArgsDeclaration>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_commands: // commands
        value.move< std::vector<std::shared_ptr<Command>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< std::vector<std::shared_ptr<Declaration>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedures: // procedures
        value.move< std::vector<std::shared_ptr<Procedure>> > (YY_MOVE (that.value));
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
      case symbol_kind::S_number: // number
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_command: // command
        value.copy< std::shared_ptr<Command> > (that.value);
        break;

      case symbol_kind::S_condition: // condition
        value.copy< std::shared_ptr<Condition> > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.copy< std::shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
        value.copy< std::shared_ptr<Identifier> > (that.value);
        break;

      case symbol_kind::S_main: // main
        value.copy< std::shared_ptr<Main> > (that.value);
        break;

      case symbol_kind::S_proc_call: // proc_call
        value.copy< std::shared_ptr<ProcCall> > (that.value);
        break;

      case symbol_kind::S_proc_head: // proc_head
        value.copy< std::shared_ptr<ProcHead> > (that.value);
        break;

      case symbol_kind::S_value: // value
        value.copy< std::shared_ptr<Value> > (that.value);
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_args: // args
        value.copy< std::vector<std::shared_ptr<Args>> > (that.value);
        break;

      case symbol_kind::S_args_decl: // args_decl
        value.copy< std::vector<std::shared_ptr<ArgsDeclaration>> > (that.value);
        break;

      case symbol_kind::S_commands: // commands
        value.copy< std::vector<std::shared_ptr<Command>> > (that.value);
        break;

      case symbol_kind::S_declarations: // declarations
        value.copy< std::vector<std::shared_ptr<Declaration>> > (that.value);
        break;

      case symbol_kind::S_procedures: // procedures
        value.copy< std::vector<std::shared_ptr<Procedure>> > (that.value);
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
      case symbol_kind::S_number: // number
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_command: // command
        value.move< std::shared_ptr<Command> > (that.value);
        break;

      case symbol_kind::S_condition: // condition
        value.move< std::shared_ptr<Condition> > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.move< std::shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< std::shared_ptr<Identifier> > (that.value);
        break;

      case symbol_kind::S_main: // main
        value.move< std::shared_ptr<Main> > (that.value);
        break;

      case symbol_kind::S_proc_call: // proc_call
        value.move< std::shared_ptr<ProcCall> > (that.value);
        break;

      case symbol_kind::S_proc_head: // proc_head
        value.move< std::shared_ptr<ProcHead> > (that.value);
        break;

      case symbol_kind::S_value: // value
        value.move< std::shared_ptr<Value> > (that.value);
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<std::shared_ptr<Args>> > (that.value);
        break;

      case symbol_kind::S_args_decl: // args_decl
        value.move< std::vector<std::shared_ptr<ArgsDeclaration>> > (that.value);
        break;

      case symbol_kind::S_commands: // commands
        value.move< std::vector<std::shared_ptr<Command>> > (that.value);
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< std::vector<std::shared_ptr<Declaration>> > (that.value);
        break;

      case symbol_kind::S_procedures: // procedures
        value.move< std::vector<std::shared_ptr<Procedure>> > (that.value);
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
      case symbol_kind::S_number: // number
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_command: // command
        yylhs.value.emplace< std::shared_ptr<Command> > ();
        break;

      case symbol_kind::S_condition: // condition
        yylhs.value.emplace< std::shared_ptr<Condition> > ();
        break;

      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< std::shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_identifier: // identifier
        yylhs.value.emplace< std::shared_ptr<Identifier> > ();
        break;

      case symbol_kind::S_main: // main
        yylhs.value.emplace< std::shared_ptr<Main> > ();
        break;

      case symbol_kind::S_proc_call: // proc_call
        yylhs.value.emplace< std::shared_ptr<ProcCall> > ();
        break;

      case symbol_kind::S_proc_head: // proc_head
        yylhs.value.emplace< std::shared_ptr<ProcHead> > ();
        break;

      case symbol_kind::S_value: // value
        yylhs.value.emplace< std::shared_ptr<Value> > ();
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_args: // args
        yylhs.value.emplace< std::vector<std::shared_ptr<Args>> > ();
        break;

      case symbol_kind::S_args_decl: // args_decl
        yylhs.value.emplace< std::vector<std::shared_ptr<ArgsDeclaration>> > ();
        break;

      case symbol_kind::S_commands: // commands
        yylhs.value.emplace< std::vector<std::shared_ptr<Command>> > ();
        break;

      case symbol_kind::S_declarations: // declarations
        yylhs.value.emplace< std::vector<std::shared_ptr<Declaration>> > ();
        break;

      case symbol_kind::S_procedures: // procedures
        yylhs.value.emplace< std::vector<std::shared_ptr<Procedure>> > ();
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
  case 2: // program_all: procedures main
#line 105 "main/parser.ypp"
                        { mainProgram(yystack_[1].value.as < std::vector<std::shared_ptr<Procedure>> > (), std::move(yystack_[0].value.as < std::shared_ptr<Main> > ())); }
#line 857 "main/parser.cpp"
    break;

  case 3: // procedures: procedures KW_PROCEDURE proc_head KW_IS declarations KW_BEGIN commands KW_END
#line 108 "main/parser.ypp"
                                                                                      { yylhs.value.as < std::vector<std::shared_ptr<Procedure>> > () = makeProcedures(yystack_[7].value.as < std::vector<std::shared_ptr<Procedure>> > (), std::move(yystack_[5].value.as < std::shared_ptr<ProcHead> > ()), yystack_[3].value.as < std::vector<std::shared_ptr<Declaration>> > (), yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > (), ProcedureEnum::WITHDECLARATION);}
#line 863 "main/parser.cpp"
    break;

  case 4: // procedures: procedures KW_PROCEDURE proc_head KW_IS KW_BEGIN commands KW_END
#line 109 "main/parser.ypp"
                                                                           { yylhs.value.as < std::vector<std::shared_ptr<Procedure>> > () = makeProcedures(yystack_[6].value.as < std::vector<std::shared_ptr<Procedure>> > (), std::move(yystack_[4].value.as < std::shared_ptr<ProcHead> > ()), yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > (), ProcedureEnum::WITHOUTDECLARATION); }
#line 869 "main/parser.cpp"
    break;

  case 5: // procedures: %empty
#line 110 "main/parser.ypp"
          { yylhs.value.as < std::vector<std::shared_ptr<Procedure>> > () = makeProcedures(); }
#line 875 "main/parser.cpp"
    break;

  case 6: // main: KW_PROGRAM KW_IS declarations KW_BEGIN commands KW_END
#line 114 "main/parser.ypp"
                                                               { yylhs.value.as < std::shared_ptr<Main> > () = std::make_shared<MainWithDecl>(yystack_[3].value.as < std::vector<std::shared_ptr<Declaration>> > (), yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > ()); }
#line 881 "main/parser.cpp"
    break;

  case 7: // main: KW_PROGRAM KW_IS KW_BEGIN commands KW_END
#line 115 "main/parser.ypp"
                                                    { yylhs.value.as < std::shared_ptr<Main> > () = std::make_shared<MainWithoutDecl>(yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > ()); }
#line 887 "main/parser.cpp"
    break;

  case 8: // commands: commands command
#line 118 "main/parser.ypp"
                         { yylhs.value.as < std::vector<std::shared_ptr<Command>> > () = makeCommands(yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > (), std::move(yystack_[0].value.as < std::shared_ptr<Command> > ()));  }
#line 893 "main/parser.cpp"
    break;

  case 9: // commands: command
#line 119 "main/parser.ypp"
                  { yylhs.value.as < std::vector<std::shared_ptr<Command>> > () = makeCommands(std::move(yystack_[0].value.as < std::shared_ptr<Command> > ())); }
#line 899 "main/parser.cpp"
    break;

  case 10: // command: identifier ASSIGN expression SEMICOLON
#line 122 "main/parser.ypp"
                                               { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandAssign>(std::move(yystack_[3].value.as < std::shared_ptr<Identifier> > ()), std::move(yystack_[1].value.as < std::shared_ptr<Expression> > ())); }
#line 905 "main/parser.cpp"
    break;

  case 11: // command: KW_IF condition KW_THEN commands KW_ENDIF
#line 123 "main/parser.ypp"
                                                    { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandIf>(std::move(yystack_[3].value.as < std::shared_ptr<Condition> > ()), yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > ()); }
#line 911 "main/parser.cpp"
    break;

  case 12: // command: KW_IF condition KW_THEN commands KW_ELSE commands KW_ENDIF
#line 124 "main/parser.ypp"
                                                                     { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandIfElse>(std::move(yystack_[5].value.as < std::shared_ptr<Condition> > ()), yystack_[3].value.as < std::vector<std::shared_ptr<Command>> > (), yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > ()); }
#line 917 "main/parser.cpp"
    break;

  case 13: // command: KW_WHILE condition KW_DO commands KW_ENDWHILE
#line 125 "main/parser.ypp"
                                                        { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandWhile>(std::move(yystack_[3].value.as < std::shared_ptr<Condition> > ()), yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > ()); }
#line 923 "main/parser.cpp"
    break;

  case 14: // command: KW_REPEAT commands KW_UNTIL condition SEMICOLON
#line 126 "main/parser.ypp"
                                                          { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandRepeat>(yystack_[3].value.as < std::vector<std::shared_ptr<Command>> > (), std::move(yystack_[1].value.as < std::shared_ptr<Condition> > ())); }
#line 929 "main/parser.cpp"
    break;

  case 15: // command: KW_FOR PIDENTIFIER KW_FROM value KW_TO value KW_DO commands KW_ENDFOR
#line 127 "main/parser.ypp"
                                                                                { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandForTo>(yystack_[7].value.as < std::string > (), std::move(yystack_[5].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[3].value.as < std::shared_ptr<Value> > ()), yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > ()); }
#line 935 "main/parser.cpp"
    break;

  case 16: // command: KW_FOR PIDENTIFIER KW_FROM value KW_DOWNTO value KW_DO commands KW_ENDFOR
#line 128 "main/parser.ypp"
                                                                                    { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandDownTo>(yystack_[7].value.as < std::string > (), std::move(yystack_[5].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[3].value.as < std::shared_ptr<Value> > ()), yystack_[1].value.as < std::vector<std::shared_ptr<Command>> > ()); }
#line 941 "main/parser.cpp"
    break;

  case 17: // command: proc_call SEMICOLON
#line 129 "main/parser.ypp"
                              { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandProcCall>(std::move(yystack_[1].value.as < std::shared_ptr<ProcCall> > ())); }
#line 947 "main/parser.cpp"
    break;

  case 18: // command: KW_READ identifier SEMICOLON
#line 130 "main/parser.ypp"
                                       { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandRead>(std::move(yystack_[1].value.as < std::shared_ptr<Identifier> > ())); }
#line 953 "main/parser.cpp"
    break;

  case 19: // command: KW_WRITE value SEMICOLON
#line 131 "main/parser.ypp"
                                   { yylhs.value.as < std::shared_ptr<Command> > () = std::make_shared<CommandWrite>(std::move(yystack_[1].value.as < std::shared_ptr<Value> > ())); }
#line 959 "main/parser.cpp"
    break;

  case 20: // proc_head: PIDENTIFIER LPRNT args_decl RPRNT
#line 134 "main/parser.ypp"
                                          { yylhs.value.as < std::shared_ptr<ProcHead> > () = makeProcHead(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<std::shared_ptr<ArgsDeclaration>> > ()); }
#line 965 "main/parser.cpp"
    break;

  case 21: // proc_call: PIDENTIFIER LPRNT args RPRNT
#line 137 "main/parser.ypp"
                                     { yylhs.value.as < std::shared_ptr<ProcCall> > () = makeProcCall(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<std::shared_ptr<Args>> > ()); }
#line 971 "main/parser.cpp"
    break;

  case 22: // declarations: declarations COMMA PIDENTIFIER
#line 140 "main/parser.ypp"
                                       { yylhs.value.as < std::vector<std::shared_ptr<Declaration>> > () = makeDeclaration(yystack_[2].value.as < std::vector<std::shared_ptr<Declaration>> > (), yystack_[0].value.as < std::string > (), {}); }
#line 977 "main/parser.cpp"
    break;

  case 23: // declarations: declarations COMMA PIDENTIFIER LBRACKET number COLON number RBRACKET
#line 141 "main/parser.ypp"
                                                                               { yylhs.value.as < std::vector<std::shared_ptr<Declaration>> > () = makeDeclaration(yystack_[7].value.as < std::vector<std::shared_ptr<Declaration>> > (), yystack_[5].value.as < std::string > (), {yystack_[3].value.as < long long > (), yystack_[1].value.as < long long > ()}); }
#line 983 "main/parser.cpp"
    break;

  case 24: // declarations: PIDENTIFIER
#line 142 "main/parser.ypp"
                      { yylhs.value.as < std::vector<std::shared_ptr<Declaration>> > () = makeDeclaration(yystack_[0].value.as < std::string > (), {}); }
#line 989 "main/parser.cpp"
    break;

  case 25: // declarations: PIDENTIFIER LBRACKET number COLON number RBRACKET
#line 143 "main/parser.ypp"
                                                            { yylhs.value.as < std::vector<std::shared_ptr<Declaration>> > () = makeDeclaration(yystack_[5].value.as < std::string > (), {yystack_[3].value.as < long long > (), yystack_[1].value.as < long long > ()}); }
#line 995 "main/parser.cpp"
    break;

  case 26: // args_decl: args_decl COMMA PIDENTIFIER
#line 146 "main/parser.ypp"
                                    { yylhs.value.as < std::vector<std::shared_ptr<ArgsDeclaration>> > () = makeArgsDeclaration(yystack_[2].value.as < std::vector<std::shared_ptr<ArgsDeclaration>> > (), yystack_[0].value.as < std::string > (), ArgsDeclarationEnum::PID); }
#line 1001 "main/parser.cpp"
    break;

  case 27: // args_decl: args_decl COMMA KW_T PIDENTIFIER
#line 147 "main/parser.ypp"
                                           { yylhs.value.as < std::vector<std::shared_ptr<ArgsDeclaration>> > () = makeArgsDeclaration(yystack_[3].value.as < std::vector<std::shared_ptr<ArgsDeclaration>> > (), yystack_[0].value.as < std::string > (), ArgsDeclarationEnum::TABLE); }
#line 1007 "main/parser.cpp"
    break;

  case 28: // args_decl: PIDENTIFIER
#line 148 "main/parser.ypp"
                      { yylhs.value.as < std::vector<std::shared_ptr<ArgsDeclaration>> > () = makeArgsDeclaration(yystack_[0].value.as < std::string > (), ArgsDeclarationEnum::PID); }
#line 1013 "main/parser.cpp"
    break;

  case 29: // args_decl: KW_T PIDENTIFIER
#line 149 "main/parser.ypp"
                           { yylhs.value.as < std::vector<std::shared_ptr<ArgsDeclaration>> > () = makeArgsDeclaration(yystack_[0].value.as < std::string > (), ArgsDeclarationEnum::TABLE); }
#line 1019 "main/parser.cpp"
    break;

  case 30: // args: args COMMA PIDENTIFIER
#line 152 "main/parser.ypp"
                               { yylhs.value.as < std::vector<std::shared_ptr<Args>> > () = makeArgs(yystack_[2].value.as < std::vector<std::shared_ptr<Args>> > (), yystack_[0].value.as < std::string > ()); }
#line 1025 "main/parser.cpp"
    break;

  case 31: // args: PIDENTIFIER
#line 153 "main/parser.ypp"
                      { yylhs.value.as < std::vector<std::shared_ptr<Args>> > () = makeArgs(yystack_[0].value.as < std::string > ()); }
#line 1031 "main/parser.cpp"
    break;

  case 32: // expression: value
#line 156 "main/parser.ypp"
              { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ExpressionEnum::VALUE); }
#line 1037 "main/parser.cpp"
    break;

  case 33: // expression: value PLUS value
#line 157 "main/parser.ypp"
                           { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ExpressionEnum::PLUS); }
#line 1043 "main/parser.cpp"
    break;

  case 34: // expression: value MINUS value
#line 158 "main/parser.ypp"
                            { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ExpressionEnum::MINUS); }
#line 1049 "main/parser.cpp"
    break;

  case 35: // expression: value MULT value
#line 159 "main/parser.ypp"
                           { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ExpressionEnum::MULT); }
#line 1055 "main/parser.cpp"
    break;

  case 36: // expression: value DIV value
#line 160 "main/parser.ypp"
                          { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ExpressionEnum::DIV); }
#line 1061 "main/parser.cpp"
    break;

  case 37: // expression: value MOD value
#line 161 "main/parser.ypp"
                          { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ExpressionEnum::MOD); }
#line 1067 "main/parser.cpp"
    break;

  case 38: // condition: value EQUAL value
#line 164 "main/parser.ypp"
                          { yylhs.value.as < std::shared_ptr<Condition> > () = std::make_shared<Condition>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ConditionEnum::EQUAL); }
#line 1073 "main/parser.cpp"
    break;

  case 39: // condition: value NEQUAL value
#line 165 "main/parser.ypp"
                             { yylhs.value.as < std::shared_ptr<Condition> > () = std::make_shared<Condition>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ConditionEnum::NOTEQUAL); }
#line 1079 "main/parser.cpp"
    break;

  case 40: // condition: value MORE value
#line 166 "main/parser.ypp"
                           { yylhs.value.as < std::shared_ptr<Condition> > () = std::make_shared<Condition>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ConditionEnum::MORE); }
#line 1085 "main/parser.cpp"
    break;

  case 41: // condition: value LESS value
#line 167 "main/parser.ypp"
                           { yylhs.value.as < std::shared_ptr<Condition> > () = std::make_shared<Condition>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ConditionEnum::LESS); }
#line 1091 "main/parser.cpp"
    break;

  case 42: // condition: value MOREOREQUAL value
#line 168 "main/parser.ypp"
                                  { yylhs.value.as < std::shared_ptr<Condition> > () = std::make_shared<Condition>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ConditionEnum::MOREOREQUAL); }
#line 1097 "main/parser.cpp"
    break;

  case 43: // condition: value LESSOREQUAL value
#line 169 "main/parser.ypp"
                                  { yylhs.value.as < std::shared_ptr<Condition> > () = std::make_shared<Condition>(std::move(yystack_[2].value.as < std::shared_ptr<Value> > ()), std::move(yystack_[0].value.as < std::shared_ptr<Value> > ()), ConditionEnum::LESSOREQUAL); }
#line 1103 "main/parser.cpp"
    break;

  case 44: // value: number
#line 172 "main/parser.ypp"
               { yylhs.value.as < std::shared_ptr<Value> > () = std::make_shared<Value>(yystack_[0].value.as < long long > (), ValueEnum::NUM); }
#line 1109 "main/parser.cpp"
    break;

  case 45: // value: identifier
#line 173 "main/parser.ypp"
                     { yylhs.value.as < std::shared_ptr<Value> > () = std::make_shared<Value>(std::move(yystack_[0].value.as < std::shared_ptr<Identifier> > ()), ValueEnum::ID); }
#line 1115 "main/parser.cpp"
    break;

  case 46: // number: NUM
#line 176 "main/parser.ypp"
            { yylhs.value.as < long long > () = yystack_[0].value.as < long long > (); }
#line 1121 "main/parser.cpp"
    break;

  case 47: // number: MINUS NUM
#line 177 "main/parser.ypp"
                                 { yylhs.value.as < long long > () = -yystack_[0].value.as < long long > (); }
#line 1127 "main/parser.cpp"
    break;

  case 48: // identifier: PIDENTIFIER
#line 180 "main/parser.ypp"
                    { yylhs.value.as < std::shared_ptr<Identifier> > () = std::make_shared<Identifier>(yystack_[0].value.as < std::string > (), IdentifierEnum::PID); }
#line 1133 "main/parser.cpp"
    break;

  case 49: // identifier: PIDENTIFIER LBRACKET number RBRACKET
#line 181 "main/parser.ypp"
                                               {  yylhs.value.as < std::shared_ptr<Identifier> > () = std::make_shared<Identifier>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < long long > (), IdentifierEnum::PIDT); }
#line 1139 "main/parser.cpp"
    break;

  case 50: // identifier: PIDENTIFIER LBRACKET PIDENTIFIER RBRACKET
#line 182 "main/parser.ypp"
                                                    {  yylhs.value.as < std::shared_ptr<Identifier> > () = std::make_shared<Identifier>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::string > (), IdentifierEnum::PIDTPID); }
#line 1145 "main/parser.cpp"
    break;


#line 1149 "main/parser.cpp"

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
  "LBRACKET", "RBRACKET", "UMINUS", "PLUS", "MINUS", "MULT", "DIV", "MOD",
  "NUM", "PIDENTIFIER", "$accept", "program_all", "procedures", "main",
  "commands", "command", "proc_head", "proc_call", "declarations",
  "args_decl", "args", "expression", "condition", "value", "number",
  "identifier", YY_NULLPTR
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


  const signed char Parser::yypact_ninf_ = -39;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     -39,     8,     9,   -39,   -38,    18,   -39,   -20,    21,    -6,
       1,    -3,   250,   -21,     4,    -2,   -39,    15,   250,     5,
      14,    14,   250,    -1,    17,    14,    27,    20,   -39,    35,
      53,   -24,   250,    41,   -39,     2,   -39,   147,   250,    43,
     -39,    55,    80,    44,   -39,   -39,    82,   155,    75,    64,
      66,    62,    40,   -39,   -39,   -39,    14,    76,   182,    85,
      79,   -39,   -39,   190,   -39,   250,    14,    14,    14,    14,
      14,    14,   250,    14,    14,   -39,   -39,   -39,    16,    88,
      89,    96,    77,   -24,   -39,   -24,   -39,   -39,   139,   -39,
     -39,   -39,   -39,   -39,   -39,   204,    97,   -14,    84,   -39,
     -39,   -39,   -39,    14,    14,    14,    14,    14,    93,    99,
     250,   -39,   -39,   -39,    14,    14,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -24,   212,   120,   121,   105,   -39,   250,
     250,   -39,   220,   242,   -39,   -39
  };

  const signed char
  Parser::yydefact_[] =
  {
       5,     0,     0,     1,     0,     0,     2,     0,     0,     0,
       0,     0,     0,    24,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,     9,     0,
       0,     0,     0,     0,    29,     0,    20,     0,     0,     0,
      46,    48,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     7,     8,    17,     0,     0,     0,    22,
       0,    26,     4,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    31,     0,     0,
       0,     0,    32,     0,     6,     0,    27,     3,     0,    38,
      39,    41,    40,    43,    42,     0,     0,     0,     0,    21,
      50,    49,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    13,    14,     0,     0,    30,    33,    34,    35,
      36,    37,    25,     0,     0,     0,     0,     0,    12,     0,
       0,    23,     0,     0,    16,    15
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -39,   -39,   -39,   -39,   -18,   -26,   -39,   -39,   125,   -39,
     -39,   -39,   -15,    34,   -28,    10
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     6,    27,    28,     8,    29,    14,    17,
      78,    81,    42,    43,    44,    30
  };

  const unsigned char
  Parser::yytable_[] =
  {
      37,    54,    12,    57,    47,    18,    46,   114,     3,     7,
     115,    54,    32,    38,    58,     4,    10,    31,    39,     5,
      63,    54,    40,    20,    80,     9,    15,    60,    11,    53,
      45,    45,    54,    21,    49,    45,    22,    54,    23,    33,
      33,    13,    24,    25,    13,    34,    48,    88,    16,    61,
      35,    98,    36,    99,    95,   108,    39,   109,    96,    50,
      40,    41,    54,    51,    41,    52,    45,    26,    55,    54,
      66,    67,    68,    69,    70,    71,    45,    45,    45,    45,
      45,    45,    39,    45,    45,    56,    40,    79,    59,    64,
      82,    65,   124,    52,    74,   127,    72,    75,    54,    76,
      89,    90,    91,    92,    93,    94,    54,    54,    97,    77,
      83,   132,   133,    45,    45,    45,    45,    45,   103,   104,
     105,   106,   107,    85,    45,    45,    86,   100,   101,   102,
     113,   116,   122,   123,   129,   130,    19,   117,   118,   119,
     120,   121,    20,   110,   131,     0,     0,     0,   125,   126,
      20,   111,    21,     0,     0,    22,    62,    23,    20,     0,
      21,    24,    25,    22,     0,    23,     0,     0,    21,    24,
      25,    22,    73,    23,     0,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,    20,    26,     0,     0,     0,
       0,    84,     0,    20,    26,    21,     0,     0,    22,    87,
      23,     0,    26,    21,    24,    25,    22,    20,    23,     0,
       0,     0,    24,    25,     0,    20,     0,    21,     0,   112,
      22,     0,    23,    20,   128,    21,    24,    25,    22,    26,
      23,     0,     0,    21,    24,    25,    22,    26,    23,     0,
     134,     0,    24,    25,     0,    20,     0,     0,     0,     0,
       0,    26,     0,    20,     0,    21,     0,     0,    22,    26,
      23,     0,   135,    21,    24,    25,    22,    26,    23,     0,
       0,     0,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,    26
  };

  const short
  Parser::yycheck_[] =
  {
      18,    27,     8,    31,    22,     8,    21,    21,     0,    47,
      24,    37,     8,     8,    32,     6,    36,    38,    42,    10,
      38,    47,    46,     3,    52,     7,    25,    25,     7,     9,
      20,    21,    58,    13,    24,    25,    16,    63,    18,    35,
      35,    47,    22,    23,    47,    47,    47,    65,    47,    47,
      35,    35,    37,    37,    72,    83,    42,    85,    73,    25,
      46,    47,    88,    36,    47,    38,    56,    47,    33,    95,
      26,    27,    28,    29,    30,    31,    66,    67,    68,    69,
      70,    71,    42,    73,    74,    32,    46,    47,    47,    46,
      56,    11,   110,    38,    19,   123,    14,    33,   124,    33,
      66,    67,    68,    69,    70,    71,   132,   133,    74,    47,
      34,   129,   130,   103,   104,   105,   106,   107,    41,    42,
      43,    44,    45,    38,   114,   115,    47,    39,    39,    33,
      33,    47,    39,    34,    14,    14,    11,   103,   104,   105,
     106,   107,     3,     4,    39,    -1,    -1,    -1,   114,   115,
       3,    12,    13,    -1,    -1,    16,     9,    18,     3,    -1,
      13,    22,    23,    16,    -1,    18,    -1,    -1,    13,    22,
      23,    16,    17,    18,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    47,    -1,    -1,    -1,
      -1,     9,    -1,     3,    47,    13,    -1,    -1,    16,     9,
      18,    -1,    47,    13,    22,    23,    16,     3,    18,    -1,
      -1,    -1,    22,    23,    -1,     3,    -1,    13,    -1,    15,
      16,    -1,    18,     3,    12,    13,    22,    23,    16,    47,
      18,    -1,    -1,    13,    22,    23,    16,    47,    18,    -1,
      20,    -1,    22,    23,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    47,    -1,     3,    -1,    13,    -1,    -1,    16,    47,
      18,    -1,    20,    13,    22,    23,    16,    47,    18,    -1,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    49,    50,     0,     6,    10,    51,    47,    54,     7,
      36,     7,     8,    47,    56,    25,    47,    57,     8,    56,
       3,    13,    16,    18,    22,    23,    47,    52,    53,    55,
      63,    38,     8,    35,    47,    35,    37,    52,     8,    42,
      46,    47,    60,    61,    62,    63,    60,    52,    47,    63,
      61,    36,    38,     9,    53,    33,    32,    62,    52,    47,
      25,    47,     9,    52,    46,    11,    26,    27,    28,    29,
      30,    31,    14,    17,    19,    33,    33,    47,    58,    47,
      62,    59,    61,    34,     9,    38,    47,     9,    52,    61,
      61,    61,    61,    61,    61,    52,    60,    61,    35,    37,
      39,    39,    33,    41,    42,    43,    44,    45,    62,    62,
       4,    12,    15,    33,    21,    24,    47,    61,    61,    61,
      61,    61,    39,    34,    52,    61,    61,    62,    12,    14,
      14,    39,    52,    52,    20,    20
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    48,    49,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    55,    56,    56,    56,    56,    57,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    60,    60,    61,    61,    62,    62,    63,    63,
      63
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     8,     7,     0,     6,     5,     2,     1,
       4,     5,     7,     5,     5,     9,     9,     2,     3,     3,
       4,     4,     3,     8,     1,     6,     3,     4,     1,     2,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     1,     4,
       4
  };




#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   105,   105,   108,   109,   110,   114,   115,   118,   119,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     134,   137,   140,   141,   142,   143,   146,   147,   148,   149,
     152,   153,   156,   157,   158,   159,   160,   161,   164,   165,
     166,   167,   168,   169,   172,   173,   176,   177,   180,   181,
     182
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
#line 1823 "main/parser.cpp"

#line 185 "main/parser.ypp"


void yy::Parser::error(const location_type& loc, const std::string& msg)
{
    std::cout << "ERROR at "<< loc << ", message: " << msg << std::endl;
}
