# CD_Lab
# CD_Lab

#Lex compilation
```
lex filename.l
gcc lex.yy.c
./a.out

```
#Terminal Using C
``` 
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Command to be executed
    char cmd[100];

    // Your CMD command here
    // Example: "dir" to list files in the current directory
    sprintf(cmd, "dir");

    // Execute the command
    system(cmd);

    return 0;
}
```
