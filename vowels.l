%{
#include <stdio.h>
%}

%% 
[a-z][a]+[a-z][e]+[a-z][i]+[a-z][o]+[a-z][u]+[a-z] {
printf("Okay the string is accepted.\n");
}
[a-z]* {printf("The string is not accepted.\n");}

%%

int main() {
  yylex();
  return 0;
}
