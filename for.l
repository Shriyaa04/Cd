%{
#include <stdio.h>
%}

%x while_head

%%

"while" {
    BEGIN(while_head);
    printf("for ");
}

<while_head>"(" {
    printf("(int i = 0;");
}

<while_head>")" {
    printf(" i < ");
}

<while_head>"{" {
    printf(" i++) {\n");
    BEGIN(INITIAL);
}

<while_head>. {
    printf("%s", yytext);
}

"}" {
    printf("\n}\n");
}

. {
    printf("%s", yytext);
}

%%

int main(void) {
    yylex();
    return 0;
}
