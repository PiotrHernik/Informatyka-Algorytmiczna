/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <iostream>
    #include <string>
    #include "definitions.hpp"

    extern FILE *yyin;
    

#line 80 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_IF = 3,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 4,                    /* KW_ELSE  */
  YYSYMBOL_NEWLINE = 5,                    /* NEWLINE  */
  YYSYMBOL_KW_PROCEDURE = 6,               /* KW_PROCEDURE  */
  YYSYMBOL_KW_IS = 7,                      /* KW_IS  */
  YYSYMBOL_KW_BEGIN = 8,                   /* KW_BEGIN  */
  YYSYMBOL_KW_END = 9,                     /* KW_END  */
  YYSYMBOL_KW_PROGRAM = 10,                /* KW_PROGRAM  */
  YYSYMBOL_KW_THEN = 11,                   /* KW_THEN  */
  YYSYMBOL_KW_ENDIF = 12,                  /* KW_ENDIF  */
  YYSYMBOL_KW_WHILE = 13,                  /* KW_WHILE  */
  YYSYMBOL_KW_DO = 14,                     /* KW_DO  */
  YYSYMBOL_KW_ENDWHILE = 15,               /* KW_ENDWHILE  */
  YYSYMBOL_KW_REPEAT = 16,                 /* KW_REPEAT  */
  YYSYMBOL_KW_UNTIL = 17,                  /* KW_UNTIL  */
  YYSYMBOL_KW_FOR = 18,                    /* KW_FOR  */
  YYSYMBOL_KW_FROM = 19,                   /* KW_FROM  */
  YYSYMBOL_KW_ENDFOR = 20,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_DOWNTO = 21,                 /* KW_DOWNTO  */
  YYSYMBOL_KW_READ = 22,                   /* KW_READ  */
  YYSYMBOL_KW_WRITE = 23,                  /* KW_WRITE  */
  YYSYMBOL_KW_TO = 24,                     /* KW_TO  */
  YYSYMBOL_KW_T = 25,                      /* KW_T  */
  YYSYMBOL_EQUAL = 26,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 27,                    /* NEQUAL  */
  YYSYMBOL_LESS = 28,                      /* LESS  */
  YYSYMBOL_MORE = 29,                      /* MORE  */
  YYSYMBOL_LESSOREQUAL = 30,               /* LESSOREQUAL  */
  YYSYMBOL_MOREOREQUAL = 31,               /* MOREOREQUAL  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 34,                     /* COLON  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_LPRNT = 36,                     /* LPRNT  */
  YYSYMBOL_RPRNT = 37,                     /* RPRNT  */
  YYSYMBOL_LBRACKET = 38,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 39,                  /* RBRACKET  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_MULT = 42,                      /* MULT  */
  YYSYMBOL_DIV = 43,                       /* DIV  */
  YYSYMBOL_MOD = 44,                       /* MOD  */
  YYSYMBOL_num = 45,                       /* num  */
  YYSYMBOL_pidentifier = 46,               /* pidentifier  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program_all = 48,               /* program_all  */
  YYSYMBOL_procedures = 49,                /* procedures  */
  YYSYMBOL_main = 50,                      /* main  */
  YYSYMBOL_commands = 51,                  /* commands  */
  YYSYMBOL_command = 52,                   /* command  */
  YYSYMBOL_proc_head = 53,                 /* proc_head  */
  YYSYMBOL_proc_call = 54,                 /* proc_call  */
  YYSYMBOL_declarations = 55,              /* declarations  */
  YYSYMBOL_args_decl = 56,                 /* args_decl  */
  YYSYMBOL_args = 57,                      /* args  */
  YYSYMBOL_expression = 58,                /* expression  */
  YYSYMBOL_condition = 59,                 /* condition  */
  YYSYMBOL_value = 60,                     /* value  */
  YYSYMBOL_identifier = 61                 /* identifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    67,    68,    69,    72,    73,    76,    77,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      92,    95,    98,    99,   100,   101,   104,   105,   106,   107,
     110,   111,   114,   115,   116,   117,   118,   119,   122,   123,
     124,   125,   126,   127,   130,   131,   134,   135,   136
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_IF", "KW_ELSE",
  "NEWLINE", "KW_PROCEDURE", "KW_IS", "KW_BEGIN", "KW_END", "KW_PROGRAM",
  "KW_THEN", "KW_ENDIF", "KW_WHILE", "KW_DO", "KW_ENDWHILE", "KW_REPEAT",
  "KW_UNTIL", "KW_FOR", "KW_FROM", "KW_ENDFOR", "KW_DOWNTO", "KW_READ",
  "KW_WRITE", "KW_TO", "KW_T", "EQUAL", "NEQUAL", "LESS", "MORE",
  "LESSOREQUAL", "MOREOREQUAL", "ASSIGN", "SEMICOLON", "COLON", "COMMA",
  "LPRNT", "RPRNT", "LBRACKET", "RBRACKET", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "num", "pidentifier", "$accept", "program_all", "procedures",
  "main", "commands", "command", "proc_head", "proc_call", "declarations",
  "args_decl", "args", "expression", "condition", "value", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -18,   -26,   -40,   -40,   144,   -40,
     -40,   -40,   -16,    65,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    27,    28,     8,    29,    14,    17,
      75,    78,    41,    42,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
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

static const yytype_int16 yycheck[] =
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    54,    55,    55,    55,    55,    56,    56,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     8,     7,     0,     6,     5,     2,     1,
       4,     7,     5,     5,     5,     9,     9,     2,     3,     3,
       4,     4,     3,     8,     1,     6,     3,     4,     1,     2,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* main: KW_PROGRAM KW_IS declarations KW_BEGIN commands KW_END  */
#line 72 "parser.y"
                                                               { std::cout << "KW_PROGRAM KW_IS declarations KW_BEGIN commands KW_END" << std::endl; }
#line 1234 "parser.cpp"
    break;

  case 7: /* main: KW_PROGRAM KW_IS KW_BEGIN commands KW_END  */
#line 73 "parser.y"
                                                    { std::cout << "KW_PROGRAM KW_IS KW_BEGIN commands KW_END" << std::endl; }
#line 1240 "parser.cpp"
    break;

  case 8: /* commands: commands command  */
#line 76 "parser.y"
                         { std::cout << "commands command" << std::endl; }
#line 1246 "parser.cpp"
    break;

  case 9: /* commands: command  */
#line 77 "parser.y"
                  { std::cout << "command" << std::endl; }
#line 1252 "parser.cpp"
    break;

  case 10: /* command: identifier ASSIGN expression SEMICOLON  */
#line 80 "parser.y"
                                               { std::cout << "identifier ASSIGN expression;" << std::endl; }
#line 1258 "parser.cpp"
    break;

  case 11: /* command: KW_IF condition KW_THEN commands KW_ELSE commands KW_ENDIF  */
#line 81 "parser.y"
                                                                     { std::cout << "KW_IF condition KW_THEN commands KW_ELSE commands KW_ENDIF" << std::endl; }
#line 1264 "parser.cpp"
    break;

  case 12: /* command: KW_IF condition KW_THEN commands KW_ENDIF  */
#line 82 "parser.y"
                                                    { std::cout << "KW_IF condition KW_THEN commands KW_ENDIF" << std::endl; }
#line 1270 "parser.cpp"
    break;

  case 13: /* command: KW_WHILE condition KW_DO commands KW_ENDWHILE  */
#line 83 "parser.y"
                                                        { std::cout << "KW_WHILE condition KW_DO commands KW_ENDWHILE" << std::endl; }
#line 1276 "parser.cpp"
    break;

  case 14: /* command: KW_REPEAT commands KW_UNTIL condition SEMICOLON  */
#line 84 "parser.y"
                                                          { std::cout << "KW_REPEAT commands KW_UNTIL condition;" << std::endl; }
#line 1282 "parser.cpp"
    break;

  case 15: /* command: KW_FOR pidentifier KW_FROM value KW_TO value KW_DO commands KW_ENDFOR  */
#line 85 "parser.y"
                                                                                { std::cout << "KW_FOR pidentifier KW_FROM value KW_TO value KW_DO commands KW_ENDFOR" << std::endl; }
#line 1288 "parser.cpp"
    break;

  case 16: /* command: KW_FOR pidentifier KW_FROM value KW_DOWNTO value KW_DO commands KW_ENDFOR  */
#line 86 "parser.y"
                                                                                    { std::cout << "KW_FOR pidentifier KW_FROM value KW_DOWNTO value KW_DO commands KW_ENDFOR" << std::endl; }
#line 1294 "parser.cpp"
    break;

  case 17: /* command: proc_call SEMICOLON  */
#line 87 "parser.y"
                              { std::cout << "proc_call;" << std::endl; }
#line 1300 "parser.cpp"
    break;

  case 18: /* command: KW_READ identifier SEMICOLON  */
#line 88 "parser.y"
                                       { std::cout << "KW_READ identifier;" << std::endl; }
#line 1306 "parser.cpp"
    break;

  case 19: /* command: KW_WRITE value SEMICOLON  */
#line 89 "parser.y"
                                   { std::cout << "KW_WRITE value;" << std::endl; }
#line 1312 "parser.cpp"
    break;

  case 20: /* proc_head: pidentifier LPRNT args_decl RPRNT  */
#line 92 "parser.y"
                                          { std::cout << "pidentifier(args_decl)" << std::endl; }
#line 1318 "parser.cpp"
    break;

  case 21: /* proc_call: pidentifier LPRNT args RPRNT  */
#line 95 "parser.y"
                                     { std::cout << "pidentifier(args)" << std::endl; }
#line 1324 "parser.cpp"
    break;

  case 22: /* declarations: declarations COMMA pidentifier  */
#line 98 "parser.y"
                                       { std::cout << "declarations, pidentifier" << std::endl; }
#line 1330 "parser.cpp"
    break;

  case 23: /* declarations: declarations COMMA pidentifier LBRACKET num COLON num RBRACKET  */
#line 99 "parser.y"
                                                                         { std::cout << "declarations, pidentifier[num:num]" << std::endl; }
#line 1336 "parser.cpp"
    break;

  case 24: /* declarations: pidentifier  */
#line 100 "parser.y"
                      { std::cout << "pidentifier1" << std::endl; }
#line 1342 "parser.cpp"
    break;

  case 25: /* declarations: pidentifier LBRACKET num COLON num RBRACKET  */
#line 101 "parser.y"
                                                      { std::cout << "pidentifier[num:num]" << std::endl; }
#line 1348 "parser.cpp"
    break;

  case 26: /* args_decl: args_decl COMMA pidentifier  */
#line 104 "parser.y"
                                    { std::cout << "args_decl, pidentifier" << std::endl; }
#line 1354 "parser.cpp"
    break;

  case 27: /* args_decl: args_decl COMMA KW_T pidentifier  */
#line 105 "parser.y"
                                           { std::cout << "args_decl, T pidentifier" << std::endl; }
#line 1360 "parser.cpp"
    break;

  case 28: /* args_decl: pidentifier  */
#line 106 "parser.y"
                      { std::cout << "pidentifier2" << std::endl; }
#line 1366 "parser.cpp"
    break;

  case 29: /* args_decl: KW_T pidentifier  */
#line 107 "parser.y"
                           { std::cout << "T pidentifier" << std::endl; }
#line 1372 "parser.cpp"
    break;

  case 30: /* args: args COMMA pidentifier  */
#line 110 "parser.y"
                               { std::cout << "args, pidentifier" << std::endl; }
#line 1378 "parser.cpp"
    break;

  case 31: /* args: pidentifier  */
#line 111 "parser.y"
                      { std::cout << "pidentifier3" << std::endl; }
#line 1384 "parser.cpp"
    break;

  case 32: /* expression: value  */
#line 114 "parser.y"
              { std::cout << "value" << std::endl; }
#line 1390 "parser.cpp"
    break;

  case 33: /* expression: value PLUS value  */
#line 115 "parser.y"
                           { std::cout << "value + value" << std::endl; }
#line 1396 "parser.cpp"
    break;

  case 34: /* expression: value MINUS value  */
#line 116 "parser.y"
                            { std::cout << "value - value" << std::endl; }
#line 1402 "parser.cpp"
    break;

  case 35: /* expression: value MULT value  */
#line 117 "parser.y"
                           { std::cout << "value * value" << std::endl; }
#line 1408 "parser.cpp"
    break;

  case 36: /* expression: value DIV value  */
#line 118 "parser.y"
                          { std::cout << "value / value" << std::endl; }
#line 1414 "parser.cpp"
    break;

  case 37: /* expression: value MOD value  */
#line 119 "parser.y"
                          { std::cout << "value % value" << std::endl; }
#line 1420 "parser.cpp"
    break;

  case 38: /* condition: value EQUAL value  */
#line 122 "parser.y"
                          { std::cout << "value == value" << std::endl; }
#line 1426 "parser.cpp"
    break;

  case 39: /* condition: value NEQUAL value  */
#line 123 "parser.y"
                             { std::cout << "value != value" << std::endl; }
#line 1432 "parser.cpp"
    break;

  case 40: /* condition: value MORE value  */
#line 124 "parser.y"
                           { std::cout << "value > value" << std::endl; }
#line 1438 "parser.cpp"
    break;

  case 41: /* condition: value LESS value  */
#line 125 "parser.y"
                           { std::cout << "value < value" << std::endl; }
#line 1444 "parser.cpp"
    break;

  case 42: /* condition: value MOREOREQUAL value  */
#line 126 "parser.y"
                                  { std::cout << "value >= value" << std::endl; }
#line 1450 "parser.cpp"
    break;

  case 43: /* condition: value LESSOREQUAL value  */
#line 127 "parser.y"
                                  { std::cout << "value <= value" << std::endl; }
#line 1456 "parser.cpp"
    break;

  case 44: /* value: num  */
#line 130 "parser.y"
            { std::cout << "num" << std::endl; }
#line 1462 "parser.cpp"
    break;

  case 45: /* value: identifier  */
#line 131 "parser.y"
                     { std::cout << "identifier: " << yyvsp[-1]<< std::endl; }
#line 1468 "parser.cpp"
    break;

  case 46: /* identifier: pidentifier  */
#line 134 "parser.y"
                    { std::cout << "pidentifier4: " << yyvsp[0] <<std::endl; }
#line 1474 "parser.cpp"
    break;

  case 47: /* identifier: pidentifier LBRACKET pidentifier RBRACKET  */
#line 135 "parser.y"
                                                    { std::cout << "pidentifier[pidentifier]" << std::endl; }
#line 1480 "parser.cpp"
    break;

  case 48: /* identifier: pidentifier LBRACKET num RBRACKET  */
#line 136 "parser.y"
                                            { std::cout << "pidentifier[num]" << std::endl; }
#line 1486 "parser.cpp"
    break;


#line 1490 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 139 "parser.y"


// int yywrap(void) { return 1; }

void yyerror(const char* yerror_msg) {
    std::cerr <<yerror_msg <<std::endl;
}

int main(int argc, char* argv[]){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin) std::cerr <<" Nie można otworzyć pliku: " <<argv[1] <<std::endl;
    }
    yyparse();
}



