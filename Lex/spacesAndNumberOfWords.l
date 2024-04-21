%{
#include<stdio.h>
#include<string.h>
char vowels[50];
int i=0;
int j=0;
char consonants[50];
int spaces = 0;
int words = 0;
%}
%%
 
[aAeEiIoOuU]   { vowels[i] = yytext[0];i++;}
[A-Za-z]       { consonants[j] = yytext[0];j++;}
[ ]            { spaces++;}  
.              ;
"\n" {printf("Total Number of Vowels : %s\nTotal Number of Consonants : %s\nTotal Number of Spaces : %d\nTotal Number of Words : %d\n", vowels,consonants,spaces,(spaces+1));spaces = 0;words = 0;}
%%
int yywrap(void){} 
int main() {
    yylex();
    return 0;
}
