#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int nfind(char *string, char *pat) {
    int lasts = strlen(string);
    int lastp = strlen(pat);

    if (lastp == 0)
        return 0;

    if (lastp > lasts) 
        return -1;

    for (int start = 0; start <= lasts - lastp; start++) {
        int endmatch = start + lastp - 1;

        if (string[endmatch] == pat[lastp - 1]) {
            int i, j;
            for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++) {
                // Match characters
            }

            if (j == lastp) {
                return start;
            }
        }
    }

    return -1;
}


void computeFailure(char *pat, int *failure) {
    int lastp = strlen(pat);
    int j = 0;

    for (int i = 1; i < lastp; i++) {
        while (j > 0 && pat[i] != pat[j]) {
            j = failure[j - 1] + 1;
        }

        if (pat[i] == pat[j]) {
            j++;
        }

        failure[i] = j - 1;
    }
}

int kmp(char *string, char *pat) {
    int i = 0, j = 0;
    int lasts = strlen(string);
    int lastp = strlen(pat);

    int *failure = malloc(lastp * sizeof(int));
    computeFailure(pat, failure);

    while (i < lasts && j < lastp) {
        if (string[i] == pat[j]) {
            i++;
            j++;
        } else if (j == 0) {
            i++;
        } else {
            j = failure[j - 1]+1;
        }
    }

    free(failure);

    return (j == lastp) ? (i - lastp) : -1;
}

int main() {
    char str[100]; 
    char pattern[50]; 
    int choice;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter a pattern to search: ");
    scanf("%s", pattern);

    printf("Enter your choice");
    printf("\n1.Nfind");
    printf("\n2.KMP");
    scanf("%d",&choice);

    if(choice == 1){
        int position = nfind(str, pattern);

        if (position != -1) {
            printf("Pattern found at position: %d\n", position);
        } 
        else {
            printf("Pattern not found in the string.\n");
        }
    }
    else if(choice == 2){
        int position = kmp(str, pattern);

        if (position != -1) {
            printf("Pattern found at position: %d\n", position);
        } 
        else {
            printf("Pattern not found in the string.\n");
        }
    }
    else{
        printf("\nInvalid choice.");
    }

    return 0;
}
