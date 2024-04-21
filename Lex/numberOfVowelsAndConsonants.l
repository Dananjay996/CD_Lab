%{
#include<stdio.h>
#include<string.h>
int vowels = 0;
int consonants = 0;
%}
%%
[aAeEiIoOuU]   { vowels++; }
[A-Za-z]       { consonants++; }
.              ;
"\n" {printf("Total Number of Vowels : %d\nTotal Number of Consonants : %d\n", vowels,consonants); vowels = 0;consonants = 0;}
%%
int yywrap(void){} 
int main() {
    yylex();
    return 0;
}
