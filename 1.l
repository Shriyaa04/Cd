%{
#include <stdio.h>
%}

%%
[-+]?[0-9]+      { printf("Matched: %s\n", yytext); }
.                { printf("Invalid input: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}
