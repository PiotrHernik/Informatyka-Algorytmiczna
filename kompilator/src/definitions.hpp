#pragma once

int yylex();
int yyparse();
void yyerror(const char* string);