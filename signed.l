%{
  #include <stdio.h>
%}

%%

[+]?[0-9]+ {printf("The number %s is unsigned",yytext);}
[-][0-9]+ {printf("The number is signed and hence invalid");}

%%
int main() {
yylex();

}
