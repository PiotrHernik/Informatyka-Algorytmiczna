%{
    
%}

%%
[--].*[\n] {}

%%

int yywrap(void){return 1;};

int main()
{
    yyin = fopen("program.adb", "r");
    yyout = fopen("test_out", "w");

    yylex();

    return 0;
}