%{
#include <stdio.h>
%}
ALPHA [A-Za-z_]
ALPHANUM [A-Za-z0-9_]
DIGIT [0-9]
%%
"int"|"else"|"if"|"else if"|"float"|"char"|"printf"    printf("Not a Valid Identifier: %s\n", yytext);
 
{ALPHA}{ALPHANUM}+     printf("Valid Identifier: %s\n", yytext);
{DIGIT}*{ALPHANUM}*     printf("Not a Valid Identifier: %s\n", yytext);
{ALPHA}{ALPHANUM}*.{ALPHANUM}*		printf("Not a Valid Identifier: %s\n", yytext);
.                     printf("Not a Valid Identifier: %s\n", yytext);
%%
int yywrap() { return 1; }
int main() {
    yylex();
    return 0;
}
