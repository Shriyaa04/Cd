%{
#include <stdio.h>
#include <string.h>
%}

%%
[0-9]* {
  int arr[27] = {0};
  int len = strlen(yytext);
  char str[len];
  strcpy(str, yytext);

  for(int i= 0;i<len;i++) {
      arr[str[i] - '0']++;
    }
  int count = 0;
  for(int i = 0;i<27;i++) {
      if(arr[i] > 1) count++;
}


if(count > 1) {printf("Invalid string");}
else {printf("Valid string");}
}

%%

int main() {
yylex();
return 0;
}
