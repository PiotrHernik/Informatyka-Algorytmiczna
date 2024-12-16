%option noyywrap

%{
    // #include <iostream>
    #include <string>
    // #include <stdio.h>
    // #include <stdlib.h>
    #include "parser.hpp"
    #include "definitions.hpp"
    int yylex();
%}

%%

"PROGRAM"           { return KW_PROGRAM; }
"PROCEDURE"         { return KW_PROCEDURE; }
"BEGIN"             { return KW_BEGIN; }
"END"               { return KW_END; }
"IS"                { return KW_IS; }
"IF"                { return KW_IF; }
"THEN"              { return KW_THEN; }
"ELSE"              { return KW_ELSE; }
"ENDIF"             { return KW_ENDIF; }
"WHILE"             { return KW_WHILE; }
"DO"                { return KW_DO; }
"ENDWHILE"          { return KW_ENDWHILE; }
"REPEAT"            { return KW_REPEAT; }
"UNTIL"             { return KW_UNTIL; }
"FOR"               { return KW_FOR; }
"FROM"              { return KW_FROM; }
"TO"                { return KW_TO; }
"ENDFOR"            { return KW_ENDFOR; }
"DOWNTO"            { return KW_DOWNTO; }
"READ"              { return KW_READ; }
"WRITE"             { return KW_WRITE; }
"T"                 { return KW_T; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULT; }
"/"                 { return DIV; }
"%"                 { return MOD; }
":="                { return ASSIGN; }
"="                 { return EQUAL; }
"!="                { return NEQUAL; }
">"                 { return MORE; }
"<"                 { return LESS; }
">="                { return MOREOREQUAL; }
"<="                { return LESSOREQUAL; }
"("                 { return LPRNT; }
")"                 { return RPRNT; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
","                 { return COMMA; }
":"                 { return COLON; }
";"                 { return SEMICOLON; }
[_a-z]+             { yylval = std::string(yytext); return pidentifier; }
[0-9]+              { return num; }
"#".*|\\n           { }
[ \t]+              { } // Ignoruj białe znaki
.                   { }

%%
