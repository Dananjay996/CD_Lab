%{
#include <stdio.h>
%}
 
DIGIT [0-9]
%%
{DIGIT}+"."{DIGIT}+    printf("Floating Point Number: %s\n", yytext);
{DIGIT}+"."            printf("Floating Point Number: %s\n", yytext);
"."{DIGIT}+          printf("Floating Point Number: %s\n", yytext);
{DIGIT}+               printf("Not a Floating Point Number: %s\n", yytext);
.                     printf("Not a Floating Point Number: %s\n", yytext);
%%
int yywrap() { return 1; }
int main() {
    yylex();
    return 0;
}
