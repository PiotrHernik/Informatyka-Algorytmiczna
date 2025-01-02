// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file main/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_MAIN_PARSER_HPP_INCLUDED
# define YY_YY_MAIN_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 19 "main/parser.ypp"


#include "../includs.hpp"
#include <string>
#include <memory>

namespace yy {
    class Scanner;
}

#line 60 "main/parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 200 "main/parser.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // NUM
      // number
      char dummy1[sizeof (long long)];

      // command
      char dummy2[sizeof (std::shared_ptr<Command>)];

      // condition
      char dummy3[sizeof (std::shared_ptr<Condition>)];

      // expression
      char dummy4[sizeof (std::shared_ptr<Expression>)];

      // identifier
      char dummy5[sizeof (std::shared_ptr<Identifier>)];

      // main
      char dummy6[sizeof (std::shared_ptr<Main>)];

      // proc_call
      char dummy7[sizeof (std::shared_ptr<ProcCall>)];

      // proc_head
      char dummy8[sizeof (std::shared_ptr<ProcHead>)];

      // value
      char dummy9[sizeof (std::shared_ptr<Value>)];

      // PIDENTIFIER
      char dummy10[sizeof (std::string)];

      // args
      char dummy11[sizeof (std::vector<std::shared_ptr<Args>>)];

      // args_decl
      char dummy12[sizeof (std::vector<std::shared_ptr<ArgsDeclaration>>)];

      // commands
      char dummy13[sizeof (std::vector<std::shared_ptr<Command>>)];

      // declarations
      char dummy14[sizeof (std::vector<std::shared_ptr<Declaration>>)];

      // procedures
      char dummy15[sizeof (std::vector<std::shared_ptr<Procedure>>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 1,                   // error
    YYUNDEF = 2,                   // "invalid token"
    KW_IF = 3,                     // KW_IF
    KW_ELSE = 4,                   // KW_ELSE
    NEWLINE = 5,                   // NEWLINE
    KW_PROCEDURE = 6,              // KW_PROCEDURE
    KW_IS = 7,                     // KW_IS
    KW_BEGIN = 8,                  // KW_BEGIN
    KW_END = 9,                    // KW_END
    KW_PROGRAM = 10,               // KW_PROGRAM
    KW_THEN = 11,                  // KW_THEN
    KW_ENDIF = 12,                 // KW_ENDIF
    KW_WHILE = 13,                 // KW_WHILE
    KW_DO = 14,                    // KW_DO
    KW_ENDWHILE = 15,              // KW_ENDWHILE
    KW_REPEAT = 16,                // KW_REPEAT
    KW_UNTIL = 17,                 // KW_UNTIL
    KW_FOR = 18,                   // KW_FOR
    KW_FROM = 19,                  // KW_FROM
    KW_ENDFOR = 20,                // KW_ENDFOR
    KW_DOWNTO = 21,                // KW_DOWNTO
    KW_READ = 22,                  // KW_READ
    KW_WRITE = 23,                 // KW_WRITE
    KW_TO = 24,                    // KW_TO
    KW_T = 25,                     // KW_T
    EQUAL = 26,                    // EQUAL
    NEQUAL = 27,                   // NEQUAL
    LESS = 28,                     // LESS
    MORE = 29,                     // MORE
    LESSOREQUAL = 30,              // LESSOREQUAL
    MOREOREQUAL = 31,              // MOREOREQUAL
    ASSIGN = 32,                   // ASSIGN
    SEMICOLON = 33,                // SEMICOLON
    COLON = 34,                    // COLON
    COMMA = 35,                    // COMMA
    LPRNT = 36,                    // LPRNT
    RPRNT = 37,                    // RPRNT
    LBRACKET = 38,                 // LBRACKET
    RBRACKET = 39,                 // RBRACKET
    UMINUS = 40,                   // UMINUS
    PLUS = 41,                     // PLUS
    MINUS = 42,                    // MINUS
    MULT = 43,                     // MULT
    DIV = 44,                      // DIV
    MOD = 45,                      // MOD
    NUM = 46,                      // NUM
    PIDENTIFIER = 47               // PIDENTIFIER
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 48, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_KW_IF = 3,                             // KW_IF
        S_KW_ELSE = 4,                           // KW_ELSE
        S_NEWLINE = 5,                           // NEWLINE
        S_KW_PROCEDURE = 6,                      // KW_PROCEDURE
        S_KW_IS = 7,                             // KW_IS
        S_KW_BEGIN = 8,                          // KW_BEGIN
        S_KW_END = 9,                            // KW_END
        S_KW_PROGRAM = 10,                       // KW_PROGRAM
        S_KW_THEN = 11,                          // KW_THEN
        S_KW_ENDIF = 12,                         // KW_ENDIF
        S_KW_WHILE = 13,                         // KW_WHILE
        S_KW_DO = 14,                            // KW_DO
        S_KW_ENDWHILE = 15,                      // KW_ENDWHILE
        S_KW_REPEAT = 16,                        // KW_REPEAT
        S_KW_UNTIL = 17,                         // KW_UNTIL
        S_KW_FOR = 18,                           // KW_FOR
        S_KW_FROM = 19,                          // KW_FROM
        S_KW_ENDFOR = 20,                        // KW_ENDFOR
        S_KW_DOWNTO = 21,                        // KW_DOWNTO
        S_KW_READ = 22,                          // KW_READ
        S_KW_WRITE = 23,                         // KW_WRITE
        S_KW_TO = 24,                            // KW_TO
        S_KW_T = 25,                             // KW_T
        S_EQUAL = 26,                            // EQUAL
        S_NEQUAL = 27,                           // NEQUAL
        S_LESS = 28,                             // LESS
        S_MORE = 29,                             // MORE
        S_LESSOREQUAL = 30,                      // LESSOREQUAL
        S_MOREOREQUAL = 31,                      // MOREOREQUAL
        S_ASSIGN = 32,                           // ASSIGN
        S_SEMICOLON = 33,                        // SEMICOLON
        S_COLON = 34,                            // COLON
        S_COMMA = 35,                            // COMMA
        S_LPRNT = 36,                            // LPRNT
        S_RPRNT = 37,                            // RPRNT
        S_LBRACKET = 38,                         // LBRACKET
        S_RBRACKET = 39,                         // RBRACKET
        S_UMINUS = 40,                           // UMINUS
        S_PLUS = 41,                             // PLUS
        S_MINUS = 42,                            // MINUS
        S_MULT = 43,                             // MULT
        S_DIV = 44,                              // DIV
        S_MOD = 45,                              // MOD
        S_NUM = 46,                              // NUM
        S_PIDENTIFIER = 47,                      // PIDENTIFIER
        S_YYACCEPT = 48,                         // $accept
        S_program_all = 49,                      // program_all
        S_procedures = 50,                       // procedures
        S_main = 51,                             // main
        S_commands = 52,                         // commands
        S_command = 53,                          // command
        S_proc_head = 54,                        // proc_head
        S_proc_call = 55,                        // proc_call
        S_declarations = 56,                     // declarations
        S_args_decl = 57,                        // args_decl
        S_args = 58,                             // args
        S_expression = 59,                       // expression
        S_condition = 60,                        // condition
        S_value = 61,                            // value
        S_number = 62,                           // number
        S_identifier = 63                        // identifier
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_number: // number
        value.move< long long > (std::move (that.value));
        break;

      case symbol_kind::S_command: // command
        value.move< std::shared_ptr<Command> > (std::move (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.move< std::shared_ptr<Condition> > (std::move (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< std::shared_ptr<Expression> > (std::move (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< std::shared_ptr<Identifier> > (std::move (that.value));
        break;

      case symbol_kind::S_main: // main
        value.move< std::shared_ptr<Main> > (std::move (that.value));
        break;

      case symbol_kind::S_proc_call: // proc_call
        value.move< std::shared_ptr<ProcCall> > (std::move (that.value));
        break;

      case symbol_kind::S_proc_head: // proc_head
        value.move< std::shared_ptr<ProcHead> > (std::move (that.value));
        break;

      case symbol_kind::S_value: // value
        value.move< std::shared_ptr<Value> > (std::move (that.value));
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<std::shared_ptr<Args>> > (std::move (that.value));
        break;

      case symbol_kind::S_args_decl: // args_decl
        value.move< std::vector<std::shared_ptr<ArgsDeclaration>> > (std::move (that.value));
        break;

      case symbol_kind::S_commands: // commands
        value.move< std::vector<std::shared_ptr<Command>> > (std::move (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< std::vector<std::shared_ptr<Declaration>> > (std::move (that.value));
        break;

      case symbol_kind::S_procedures: // procedures
        value.move< std::vector<std::shared_ptr<Procedure>> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long long&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long long& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Command>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Command>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Condition>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Condition>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Expression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Expression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Identifier>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Identifier>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Main>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Main>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ProcCall>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ProcCall>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ProcHead>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ProcHead>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Value>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Value>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::shared_ptr<Args>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<Args>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::shared_ptr<ArgsDeclaration>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<ArgsDeclaration>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::shared_ptr<Command>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<Command>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::shared_ptr<Declaration>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<Declaration>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::shared_ptr<Procedure>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<Procedure>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_number: // number
        value.template destroy< long long > ();
        break;

      case symbol_kind::S_command: // command
        value.template destroy< std::shared_ptr<Command> > ();
        break;

      case symbol_kind::S_condition: // condition
        value.template destroy< std::shared_ptr<Condition> > ();
        break;

      case symbol_kind::S_expression: // expression
        value.template destroy< std::shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_identifier: // identifier
        value.template destroy< std::shared_ptr<Identifier> > ();
        break;

      case symbol_kind::S_main: // main
        value.template destroy< std::shared_ptr<Main> > ();
        break;

      case symbol_kind::S_proc_call: // proc_call
        value.template destroy< std::shared_ptr<ProcCall> > ();
        break;

      case symbol_kind::S_proc_head: // proc_head
        value.template destroy< std::shared_ptr<ProcHead> > ();
        break;

      case symbol_kind::S_value: // value
        value.template destroy< std::shared_ptr<Value> > ();
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_args: // args
        value.template destroy< std::vector<std::shared_ptr<Args>> > ();
        break;

      case symbol_kind::S_args_decl: // args_decl
        value.template destroy< std::vector<std::shared_ptr<ArgsDeclaration>> > ();
        break;

      case symbol_kind::S_commands: // commands
        value.template destroy< std::vector<std::shared_ptr<Command>> > ();
        break;

      case symbol_kind::S_declarations: // declarations
        value.template destroy< std::vector<std::shared_ptr<Declaration>> > ();
        break;

      case symbol_kind::S_procedures: // procedures
        value.template destroy< std::vector<std::shared_ptr<Procedure>> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::MOD));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long long v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const long long& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::NUM);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::PIDENTIFIER);
#endif
      }
    };

    /// Build a parser object.
    Parser (yy::Scanner &scanner_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_IF (location_type l)
      {
        return symbol_type (token::KW_IF, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_IF (const location_type& l)
      {
        return symbol_type (token::KW_IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_ELSE (location_type l)
      {
        return symbol_type (token::KW_ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_ELSE (const location_type& l)
      {
        return symbol_type (token::KW_ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEWLINE (location_type l)
      {
        return symbol_type (token::NEWLINE, std::move (l));
      }
#else
      static
      symbol_type
      make_NEWLINE (const location_type& l)
      {
        return symbol_type (token::NEWLINE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_PROCEDURE (location_type l)
      {
        return symbol_type (token::KW_PROCEDURE, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_PROCEDURE (const location_type& l)
      {
        return symbol_type (token::KW_PROCEDURE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_IS (location_type l)
      {
        return symbol_type (token::KW_IS, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_IS (const location_type& l)
      {
        return symbol_type (token::KW_IS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_BEGIN (location_type l)
      {
        return symbol_type (token::KW_BEGIN, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_BEGIN (const location_type& l)
      {
        return symbol_type (token::KW_BEGIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_END (location_type l)
      {
        return symbol_type (token::KW_END, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_END (const location_type& l)
      {
        return symbol_type (token::KW_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_PROGRAM (location_type l)
      {
        return symbol_type (token::KW_PROGRAM, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_PROGRAM (const location_type& l)
      {
        return symbol_type (token::KW_PROGRAM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_THEN (location_type l)
      {
        return symbol_type (token::KW_THEN, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_THEN (const location_type& l)
      {
        return symbol_type (token::KW_THEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_ENDIF (location_type l)
      {
        return symbol_type (token::KW_ENDIF, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_ENDIF (const location_type& l)
      {
        return symbol_type (token::KW_ENDIF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_WHILE (location_type l)
      {
        return symbol_type (token::KW_WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_WHILE (const location_type& l)
      {
        return symbol_type (token::KW_WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_DO (location_type l)
      {
        return symbol_type (token::KW_DO, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_DO (const location_type& l)
      {
        return symbol_type (token::KW_DO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_ENDWHILE (location_type l)
      {
        return symbol_type (token::KW_ENDWHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_ENDWHILE (const location_type& l)
      {
        return symbol_type (token::KW_ENDWHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_REPEAT (location_type l)
      {
        return symbol_type (token::KW_REPEAT, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_REPEAT (const location_type& l)
      {
        return symbol_type (token::KW_REPEAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_UNTIL (location_type l)
      {
        return symbol_type (token::KW_UNTIL, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_UNTIL (const location_type& l)
      {
        return symbol_type (token::KW_UNTIL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_FOR (location_type l)
      {
        return symbol_type (token::KW_FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_FOR (const location_type& l)
      {
        return symbol_type (token::KW_FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_FROM (location_type l)
      {
        return symbol_type (token::KW_FROM, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_FROM (const location_type& l)
      {
        return symbol_type (token::KW_FROM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_ENDFOR (location_type l)
      {
        return symbol_type (token::KW_ENDFOR, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_ENDFOR (const location_type& l)
      {
        return symbol_type (token::KW_ENDFOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_DOWNTO (location_type l)
      {
        return symbol_type (token::KW_DOWNTO, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_DOWNTO (const location_type& l)
      {
        return symbol_type (token::KW_DOWNTO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_READ (location_type l)
      {
        return symbol_type (token::KW_READ, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_READ (const location_type& l)
      {
        return symbol_type (token::KW_READ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_WRITE (location_type l)
      {
        return symbol_type (token::KW_WRITE, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_WRITE (const location_type& l)
      {
        return symbol_type (token::KW_WRITE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_TO (location_type l)
      {
        return symbol_type (token::KW_TO, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_TO (const location_type& l)
      {
        return symbol_type (token::KW_TO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KW_T (location_type l)
      {
        return symbol_type (token::KW_T, std::move (l));
      }
#else
      static
      symbol_type
      make_KW_T (const location_type& l)
      {
        return symbol_type (token::KW_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (location_type l)
      {
        return symbol_type (token::EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const location_type& l)
      {
        return symbol_type (token::EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEQUAL (location_type l)
      {
        return symbol_type (token::NEQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_NEQUAL (const location_type& l)
      {
        return symbol_type (token::NEQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (location_type l)
      {
        return symbol_type (token::LESS, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS (const location_type& l)
      {
        return symbol_type (token::LESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MORE (location_type l)
      {
        return symbol_type (token::MORE, std::move (l));
      }
#else
      static
      symbol_type
      make_MORE (const location_type& l)
      {
        return symbol_type (token::MORE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESSOREQUAL (location_type l)
      {
        return symbol_type (token::LESSOREQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_LESSOREQUAL (const location_type& l)
      {
        return symbol_type (token::LESSOREQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOREOREQUAL (location_type l)
      {
        return symbol_type (token::MOREOREQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_MOREOREQUAL (const location_type& l)
      {
        return symbol_type (token::MOREOREQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPRNT (location_type l)
      {
        return symbol_type (token::LPRNT, std::move (l));
      }
#else
      static
      symbol_type
      make_LPRNT (const location_type& l)
      {
        return symbol_type (token::LPRNT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPRNT (location_type l)
      {
        return symbol_type (token::RPRNT, std::move (l));
      }
#else
      static
      symbol_type
      make_RPRNT (const location_type& l)
      {
        return symbol_type (token::RPRNT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (location_type l)
      {
        return symbol_type (token::LBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const location_type& l)
      {
        return symbol_type (token::LBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (location_type l)
      {
        return symbol_type (token::RBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const location_type& l)
      {
        return symbol_type (token::RBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS (location_type l)
      {
        return symbol_type (token::UMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_UMINUS (const location_type& l)
      {
        return symbol_type (token::UMINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT (location_type l)
      {
        return symbol_type (token::MULT, std::move (l));
      }
#else
      static
      symbol_type
      make_MULT (const location_type& l)
      {
        return symbol_type (token::MULT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (location_type l)
      {
        return symbol_type (token::DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const location_type& l)
      {
        return symbol_type (token::DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUM (long long v, location_type l)
      {
        return symbol_type (token::NUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUM (const long long& v, const location_type& l)
      {
        return symbol_type (token::NUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::PIDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PIDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PIDENTIFIER, v, l);
      }
#endif


    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 297,     ///< Last index in yytable_.
      yynnts_ = 16,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    yy::Scanner &scanner;

  };

  inline
  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_number: // number
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_command: // command
        value.copy< std::shared_ptr<Command> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condition: // condition
        value.copy< std::shared_ptr<Condition> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.copy< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.copy< std::shared_ptr<Identifier> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_main: // main
        value.copy< std::shared_ptr<Main> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc_call: // proc_call
        value.copy< std::shared_ptr<ProcCall> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_proc_head: // proc_head
        value.copy< std::shared_ptr<ProcHead> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_value: // value
        value.copy< std::shared_ptr<Value> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args: // args
        value.copy< std::vector<std::shared_ptr<Args>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args_decl: // args_decl
        value.copy< std::vector<std::shared_ptr<ArgsDeclaration>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_commands: // commands
        value.copy< std::vector<std::shared_ptr<Command>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.copy< std::vector<std::shared_ptr<Declaration>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedures: // procedures
        value.copy< std::vector<std::shared_ptr<Procedure>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




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
    switch (this->kind ())
    {
      case symbol_kind::S_NUM: // NUM
      case symbol_kind::S_number: // number
        value.move< long long > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_command: // command
        value.move< std::shared_ptr<Command> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_condition: // condition
        value.move< std::shared_ptr<Condition> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< std::shared_ptr<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_identifier: // identifier
        value.move< std::shared_ptr<Identifier> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_main: // main
        value.move< std::shared_ptr<Main> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_proc_call: // proc_call
        value.move< std::shared_ptr<ProcCall> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_proc_head: // proc_head
        value.move< std::shared_ptr<ProcHead> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_value: // value
        value.move< std::shared_ptr<Value> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_PIDENTIFIER: // PIDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<std::shared_ptr<Args>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_args_decl: // args_decl
        value.move< std::vector<std::shared_ptr<ArgsDeclaration>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_commands: // commands
        value.move< std::vector<std::shared_ptr<Command>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declarations: // declarations
        value.move< std::vector<std::shared_ptr<Declaration>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_procedures: // procedures
        value.move< std::vector<std::shared_ptr<Procedure>> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2541 "main/parser.hpp"




#endif // !YY_YY_MAIN_PARSER_HPP_INCLUDED
