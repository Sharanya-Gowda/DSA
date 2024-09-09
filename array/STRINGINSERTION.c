#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void strnins(char *s, const char *t, int i) {
    char temp[MAX_SIZE];

    if (i < 0 || i > strlen(s)) {
        fprintf(stderr, "Position is out of bounds\n");
        exit(EXIT_FAILURE);
    }

    if (strlen(s) == 0) {
        strcpy(s, t);
    } else if (strlen(t) > 0) {
        strncpy(temp, s, i);
        temp[i] = '\0'; // Null-terminate the substring
        strcat(temp, t);
        strcat(temp, s + i);
        strcpy(s, temp);
    }
}

int main() {
    char inputstring[MAX_SIZE];
    char insertstring[MAX_SIZE];
    int position;

    printf("\nEnter the string");
    scanf("%s",inputstring);
    printf("\nEnter the string to be inserted");
    scanf("%s",insertstring);
    printf("\nEnter the position");
    scanf("%d",&position);

    strnins(inputstring,insertstring,position);
    printf("New string:%s\n",inputstring);

    return 0;
}