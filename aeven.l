%{
#include <stdio.h>
int count_a = 0;
int count_b = 0;
%}

%%

[a]    { count_a++; }
[b]    { count_b++; }

%%

int main() {
    yylex();
  if(count_a % 2 == 0 && count_b %2 != 0) {
    printf("The string contains even number of a's and odd number of b's");
  }
else {printf("Invalid string");}
    return 0;
}
