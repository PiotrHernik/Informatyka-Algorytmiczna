%{
    int doxygen_enabled;
%}

%s doxygen

%%
    if (doxygen_enabled) { BEGIN(doxygen);} else { BEGIN(INITIAL);}

.*["].*["][;]?[\n] {fprintf(yyout, "%s", yytext);}
<doxygen>[/][*]{2}([ \t]*[\n])*([ \t]*[*].*[\n])*[ \t]*[*][/] {} // /** */
<doxygen>[/][*][!]([ \t]*[\n])*([ \t]*[*].*[\n])*[ \t]*[*][/] {} // /*! */
<doxygen>[ ]*[\/]{3}.*[\n] {} // ///
<doxygen>[ ]*[\/]{2}[!].*[\n] {} // //!
[/][*]([ \t]*[\n])*([^\*]|\*[^\/])*[ \t]*[*][/] {} // /* */
^[ \t]*[/]{2}.*\n {} // //
[/]{2}.* {}

%%

int yywrap(void){return 1;};

int main(int argc, char* argv[])
{
    if (getchar() == 'd') doxygen_enabled = 1;
   

    yyin = fopen("program.cpp", "r");
    yyout = fopen("test_out.cpp", "w");

    yylex();

    return 0;
}