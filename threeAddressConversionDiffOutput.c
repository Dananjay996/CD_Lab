#include <stdio.h>
int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    printf("Three Address Code: \n");
    int flag=0;
    int st[10];
    int stc=0;
    int i=2;
    int j=0;
    printf("Operator\tInput1\tInput2\tOutput\n");
    while(expression[i]!= '\0') {
        if((expression[i]=='+'|| expression[i]=='-'|| expression[i]=='*'|| expression[i]=='/')&&expression[i+1]!='(' &&expression[i-1]!=')'){
            if (j==0){
                printf("%c\t\t\t%c\t\t%c\t\tT1\n", expression[i], expression[i-1], expression[i+1]);
                j++;
            }
            else{
                printf("%c\t\t\tT%d\t\t%c\t\tT%d\n",expression[i],j,expression[i+1],j+1);
                j++;
            }
        }
        else if(expression[i+1]=='('){
            st[stc]=expression[i-1];
            stc++;
            st[stc]=expression[i];
            stc++;
        }
        else if(expression[i+1]==')'){
            st[stc]=expression[i+2];
            stc++;
            st[stc]=expression[i+3];
            printf("%c\t\t\t%c\t\tT%d\t\tT%d\n",st[1],st[0],j,j+1);
            j++;
            printf("%c\t\t\tT%d\t\t%c\t\tT%d\n",st[2],j,st[3],j+1);
            j++;
        }
    i++;
}
    printf("=\t\t\tT%d\t\t\t\t%c", j,expression[0]);
    return 0;
}
