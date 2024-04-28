#include <stdio.h>

int main(){

printf("Enter number of production rules:");

int n;

scanf("%d",&n);

char a[n][50];

printf("Enter the production rules:\n");

for(int i=0;i<n;i++){
  scanf("%19s",a[i]);
}
printf("\nYou entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s", i + 1, a[i]);
    }

for(int i=0;i<n;i++){

if (a[i][0]==a[i][3]){

printf("%s has left recursion\n",a[i]);

printf("%c->%c'\n",a[i][0],a[i][0]);

printf("%c'->",a[i][0]);
int j=4;

while(a[i][j]!='\0'){

printf("%c",a[i][j]);

j++;

}

printf("%c'\n",a[i][0]);

}

}

}
