/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_IF = 258,                   /* KW_IF  */
    KW_ELSE = 259,                 /* KW_ELSE  */
    NEWLINE = 260,                 /* NEWLINE  */
    KW_PROCEDURE = 261,            /* KW_PROCEDURE  */
    KW_IS = 262,                   /* KW_IS  */
    KW_BEGIN = 263,                /* KW_BEGIN  */
    KW_END = 264,                  /* KW_END  */
    KW_PROGRAM = 265,              /* KW_PROGRAM  */
    KW_THEN = 266,                 /* KW_THEN  */
    KW_ENDIF = 267,                /* KW_ENDIF  */
    KW_WHILE = 268,                /* KW_WHILE  */
    KW_DO = 269,                   /* KW_DO  */
    KW_ENDWHILE = 270,             /* KW_ENDWHILE  */
    KW_REPEAT = 271,               /* KW_REPEAT  */
    KW_UNTIL = 272,                /* KW_UNTIL  */
    KW_FOR = 273,                  /* KW_FOR  */
    KW_FROM = 274,                 /* KW_FROM  */
    KW_ENDFOR = 275,               /* KW_ENDFOR  */
    KW_DOWNTO = 276,               /* KW_DOWNTO  */
    KW_READ = 277,                 /* KW_READ  */
    KW_WRITE = 278,                /* KW_WRITE  */
    KW_TO = 279,                   /* KW_TO  */
    KW_T = 280,                    /* KW_T  */
    EQUAL = 281,                   /* EQUAL  */
    NEQUAL = 282,                  /* NEQUAL  */
    LESS = 283,                    /* LESS  */
    MORE = 284,                    /* MORE  */
    LESSOREQUAL = 285,             /* LESSOREQUAL  */
    MOREOREQUAL = 286,             /* MOREOREQUAL  */
    ASSIGN = 287,                  /* ASSIGN  */
    SEMICOLON = 288,               /* SEMICOLON  */
    COLON = 289,                   /* COLON  */
    COMMA = 290,                   /* COMMA  */
    LPRNT = 291,                   /* LPRNT  */
    RPRNT = 292,                   /* RPRNT  */
    LBRACKET = 293,                /* LBRACKET  */
    RBRACKET = 294,                /* RBRACKET  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    MULT = 297,                    /* MULT  */
    DIV = 298,                     /* DIV  */
    MOD = 299,                     /* MOD  */
    num = 300,                     /* num  */
    pidentifier = 301              /* pidentifier  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef std::string YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
