%{
    #include<math.h>
    #define stack_size 100
    #define error_buff_size 100
    static int stack[stack_size];
    static char ERROR[error_buff_size];
    static int top = -1;
    static int pop(){
        if(top >= 0) return stack[top--]; 
        else sprintf(ERROR, "err: Less numbers than expected\n");
    }
    static void push(int i){
        if(++top < stack_size) stack[top] = i;
        else sprintf(ERROR, "Stack overflow\n");
    }
    static int myPow(int a, int b){
        return pow(a, b);
    }
%}

%%
q {return 0;}
-?[0-9] {push(atoi(yytext));}
\+ {push(pop() + pop());}
\- {int odjemnik = pop(); push(pop() - odjemnik);}
\* {push(pop() * pop());}
\/ {int dzielnik = pop(); 
    if(dzielnik == 0) sprintf(ERROR, "divide by 0\n");
    else push(pop() / dzielnik);}
\% {int he = pop(); 
    if(he == 0) sprintf(ERROR, "divide by 0\n");
    else push(pop() % he);}
\^ {int wykladnik = pop();
    if( wykladnik < 0) sprintf(ERROR, "only natural\n");
    else push(myPow(pop(), wykladnik));}
[ \t] {}

\n {
    if(*ERROR != '\0') puts(ERROR);
    else if(top == -1) puts("err: Empty input\n");
    else if (top > 0) puts("err: Too many numbers\n");
    else printf("= %d\n", pop());

    top = -1;
    *ERROR = '\0';
}
. { sprintf(ERROR, "err: Invalid character - %s\n", yytext); } 
%%

int yywrap(void) { return 1; }

#include<math.h>
int main(void) {
    yylex();
    return 0;
}