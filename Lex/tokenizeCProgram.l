%{
#include <stdio.h>
%}
%%
[0-9]+                          { printf("NUMBER: %s\n", yytext); }
"int"|"printf"|"float"             { printf("KEYWORD: %s\n", yytext); } 
[a-zA-Z][a-zA-Z0-9_]*           { printf("IDENTIFIER: %s\n", yytext); }
"=="|"!="|"<="|">="|"="|"<"|">" { printf("OPERATOR: %s\n", yytext); }
"+"|"-"|"*"|"/"                 { printf("OPERATOR: %s\n", yytext); }
"("|")"|";"|","                 { printf("DELIMITER: %s\n", yytext); }
[ \t\n]                         ; // ignore whitespace
.                               { printf("INVALID CHARACTER: %s\n", yytext); }
%%
int yywrap(void){} 
int main() {
   yylex();
   return 0;
}
