#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int hasSingleLineComment(const char *line) {
   return (strstr(line, "//") != NULL);
}


int hasMultiLineCommentStart(const char *line) {
   return (strstr(line, "/*") != NULL);
}

int hasMultiLineCommentEnd(const char *line) {
    return (strstr(line, "*/") != NULL);
}

// Function to check if a token is a keyword
int isKeyword(const char *token) {
    // Add more keywords as needed
    const char *keywords[] = {"int", "char", "if", "else", "while", "for"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }

    return 0; // Not a keyword
}

// Function to check if a token is a valid identifier
int isValidIdentifier(const char *token) {
    if (!isalpha(token[0]) && token[0] != '_') {
        return 0; // Invalid identifier
    }

    for (int i = 1; i < strlen(token); i++) {
        if (!isalnum(token[i]) && token[i] != '_') {
            return 0; // Invalid identifier
        }
    }

    return 1; // Valid identifier
}

// Function to classify and print the category of a token
void classifyToken(char *token) {
    if (isKeyword(token)) {
        printf("Keyword: %s\n", token);
    } else if (isValidIdentifier(token)) {
        printf("Identifier: %s\n", token);
    } else if (isdigit(token[0])) {
        printf("Constant: %s\n", token);
    } else if (ispunct(token[0])) {
        printf("Operator: %s\n", token);
    } else if (token[0] == '#') {
        printf("Preprocessor Directive: %s\n", token);
    } else {
        printf("Invalid: %s\n", token);
    }
}

// Function to tokenize a given line
void tokenizeLine(char *line) {
    char *token = strtok(line, " \t\n");  // Tokenize based on space, tab, and newline

    while (token != NULL) {
        classifyToken(token);
        token = strtok(NULL, " \t\n");
    }
}

int main() {
    FILE *fptr;
    char line[MAX_LINE_LENGTH];

    // Open the C file for reading
    fptr = fopen("commentFromFile.c", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read and tokenize each line in the file
    while (fgets(line, MAX_LINE_LENGTH, fptr) != NULL) {
        tokenizeLine(line);
    }

    fclose(fptr);

    return 0;
}