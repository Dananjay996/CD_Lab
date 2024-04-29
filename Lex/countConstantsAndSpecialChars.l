%{
#include <stdio.h>
int constant_count = 0;
int special_char_count = 0;
%}

%%
[ \t\n]+[0-9]+[ \t\n]+       { constant_count++; printf("%s",yytext); } // Match numeric literals
[^a-zA-Z0-9 \t\n]   { special_char_count++; } // Match special characters
.               ; // Match any other character (like whitespace)
%%

int yywrap(void) {}

int main() {
    yylex(); // Call the generated lexical analyzer
    printf("Total constants: %d\n", constant_count);
    printf("Total special characters: %d\n", special_char_count);
    return 0;
}
