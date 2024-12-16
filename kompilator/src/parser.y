%{
    #include <iostream>
    #include <string>
    #include "definitions.hpp"

    extern FILE *yyin;
    
%}

%define api.value.type {std::string}

%token KW_IF 
%token KW_ELSE
%token NEWLINE
%token KW_PROCEDURE 
%token KW_IS 
%token KW_BEGIN 
%token KW_END
%token KW_PROGRAM
%token KW_THEN
%token KW_ENDIF
%token KW_WHILE 
%token KW_DO
%token KW_ENDWHILE
%token KW_REPEAT
%token KW_UNTIL
%token KW_FOR
%token KW_FROM
%token KW_ENDFOR
%token KW_DOWNTO
%token KW_READ
%token KW_WRITE
%token KW_TO
%token KW_T

%token EQUAL
%token NEQUAL
%token LESS
%token MORE
%token LESSOREQUAL
%token MOREOREQUAL

%token ASSIGN

%token SEMICOLON
%token COLON
%token COMMA
%token LPRNT
%token RPRNT
%token LBRACKET
%token RBRACKET

%token PLUS 
%token MINUS
%token MULT
%token DIV
%token MOD

%token num
%token pidentifier

%%
program_all: 
        procedures main

procedures: 
        procedures KW_PROCEDURE proc_head KW_IS declarations KW_BEGIN commands KW_END
        | procedures KW_PROCEDURE proc_head KW_IS KW_BEGIN commands KW_END
        | 

main: 
        KW_PROGRAM KW_IS declarations KW_BEGIN commands KW_END { std::cout << "KW_PROGRAM KW_IS declarations KW_BEGIN commands KW_END" << std::endl; }
        | KW_PROGRAM KW_IS KW_BEGIN commands KW_END { std::cout << "KW_PROGRAM KW_IS KW_BEGIN commands KW_END" << std::endl; }

commands:
        commands command { std::cout << "commands command" << std::endl; }
        | command { std::cout << "command" << std::endl; }

command:
        identifier ASSIGN expression SEMICOLON { std::cout << "identifier ASSIGN expression;" << std::endl; }
        | KW_IF condition KW_THEN commands KW_ELSE commands KW_ENDIF { std::cout << "KW_IF condition KW_THEN commands KW_ELSE commands KW_ENDIF" << std::endl; }
        | KW_IF condition KW_THEN commands KW_ENDIF { std::cout << "KW_IF condition KW_THEN commands KW_ENDIF" << std::endl; }
        | KW_WHILE condition KW_DO commands KW_ENDWHILE { std::cout << "KW_WHILE condition KW_DO commands KW_ENDWHILE" << std::endl; }
        | KW_REPEAT commands KW_UNTIL condition SEMICOLON { std::cout << "KW_REPEAT commands KW_UNTIL condition;" << std::endl; }
        | KW_FOR pidentifier KW_FROM value KW_TO value KW_DO commands KW_ENDFOR { std::cout << "KW_FOR pidentifier KW_FROM value KW_TO value KW_DO commands KW_ENDFOR" << std::endl; }
        | KW_FOR pidentifier KW_FROM value KW_DOWNTO value KW_DO commands KW_ENDFOR { std::cout << "KW_FOR pidentifier KW_FROM value KW_DOWNTO value KW_DO commands KW_ENDFOR" << std::endl; }
        | proc_call SEMICOLON { std::cout << "proc_call;" << std::endl; }
        | KW_READ identifier SEMICOLON { std::cout << "KW_READ identifier;" << std::endl; }
        | KW_WRITE value SEMICOLON { std::cout << "KW_WRITE value;" << std::endl; }

proc_head:
        pidentifier LPRNT args_decl RPRNT { std::cout << "pidentifier(args_decl)" << std::endl; }

proc_call:
        pidentifier LPRNT args RPRNT { std::cout << "pidentifier(args)" << std::endl; }

declarations:
        declarations COMMA pidentifier { std::cout << "declarations, pidentifier" << std::endl; }
        | declarations COMMA pidentifier LBRACKET num COLON num RBRACKET { std::cout << "declarations, pidentifier[num:num]" << std::endl; }
        | pidentifier { std::cout << "pidentifier1" << std::endl; }
        | pidentifier LBRACKET num COLON num RBRACKET { std::cout << "pidentifier[num:num]" << std::endl; }

args_decl:
        args_decl COMMA pidentifier { std::cout << "args_decl, pidentifier" << std::endl; }
        | args_decl COMMA KW_T pidentifier { std::cout << "args_decl, T pidentifier" << std::endl; }
        | pidentifier { std::cout << "pidentifier2" << std::endl; }
        | KW_T pidentifier { std::cout << "T pidentifier" << std::endl; }

args:
        args COMMA pidentifier { std::cout << "args, pidentifier" << std::endl; }
        | pidentifier { std::cout << "pidentifier3" << std::endl; }

expression:
        value { std::cout << "value" << std::endl; }
        | value PLUS value { std::cout << "value + value" << std::endl; }
        | value MINUS value { std::cout << "value - value" << std::endl; }
        | value MULT value { std::cout << "value * value" << std::endl; }
        | value DIV value { std::cout << "value / value" << std::endl; }
        | value MOD value { std::cout << "value % value" << std::endl; }

condition:
        value EQUAL value { std::cout << "value == value" << std::endl; }
        | value NEQUAL value { std::cout << "value != value" << std::endl; }
        | value MORE value { std::cout << "value > value" << std::endl; }
        | value LESS value { std::cout << "value < value" << std::endl; }
        | value MOREOREQUAL value { std::cout << "value >= value" << std::endl; }
        | value LESSOREQUAL value { std::cout << "value <= value" << std::endl; }

value:
        num { std::cout << "num" << std::endl; }
        | identifier { std::cout << "identifier: " << $0<< std::endl; }

identifier:
        pidentifier { std::cout << "pidentifier4: " << $1 <<std::endl; }
        | pidentifier LBRACKET pidentifier RBRACKET { std::cout << "pidentifier[pidentifier]" << std::endl; }
        | pidentifier LBRACKET num RBRACKET { std::cout << "pidentifier[num]" << std::endl; }


%%

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



