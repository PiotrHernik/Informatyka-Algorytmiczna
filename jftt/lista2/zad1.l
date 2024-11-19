%{
    int words = 0;
    int lines = 0;
%}

%%
^[ \t]*\n? {}
[ \t]+\n {fprintf(yyout, "\n"); words++, lines++;}
[ \t]+ {fprintf(yyout, " "); words++;}
\n { fprintf(yyout, "%s", yytext); words++, lines++;} // just new line
<<EOF>> { words++, lines++ ; return 0;}

%%

int yywrap(void){return 1;};

int main()
{
    yyin = fopen("test", "r");
    yyout = fopen("test_out", "w");

    yylex();
    fprintf(yyout, "\nwords: %d, lines: %d", words, lines);

    return 0;
}