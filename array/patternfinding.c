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

int main() {
    char str[100]; 
    char pattern[50]; 

    printf("Enter the string: ");
    scanf("%s", str);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    int position = nfind(str, pattern);

    if (position != -1) {
        printf("Pattern found at position: %d\n", position);
    } else {
        printf("Pattern not found in the string.\n");
    }
    return 0;
}
