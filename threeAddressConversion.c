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
    while(expression[i]!= '\0') {
        if((expression[i]=='+'|| expression[i]=='-'|| expression[i]=='*'|| expression[i]=='/')&&expression[i+1]!='(' &&expression[i-1]!=')'){
            if (j==0){
                printf("T1=%c%c%c\n", expression[i-1], expression[i], expression[i+1]);
                j++;
            }
            else{
                printf("T%d=T%d%c%c\n",j+1,j,expression[i],expression[i+1]);
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
            printf("T%d=%c%cT%d\n",j+1,st[0],st[1],j);
            j++;
            printf("T%d=T%d%c%c\n",j+1,j,st[2],st[3]);
            j++;
        }
    i++;
}
    printf("%c= T%d", expression[0],j);
    return 0;
}
