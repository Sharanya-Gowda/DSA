#include <stdio.h>
#define MAX_TERMS 101
#define MAX_COL 10

typedef struct {
    int row;
    int col;
    int value;
} term;

void simpletranspose(term a[], term b[]) {
    int n, i, j, currentb;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;
    if (n > 0) {
        currentb = 1;
        for (i = 0; i < a[0].col; i++) {
            for (j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}
void fastTranspose(term a[], term b[]) {
    int rowTerms[MAX_COL], starting_pos[MAX_COL];
    int i, j, numcols = a[0].col, numTerms = a[0].value;
    b[0].row = numcols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    if (numTerms > 0) {
        for (i = 0; i < numcols; i++) {
            rowTerms[i] = 0;
        }
        for (i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
        }
        starting_pos[0] = 1;
        for (i = 1; i < numcols; i++) {
            starting_pos[i] = starting_pos[i - 1] + rowTerms[i - 1];
        }
        for (i = 1; i <= numTerms; i++) {
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

void displayMatrix(term a[]) {
    int i, j, k = 1;
    int rows = a[0].row;
    int cols = a[0].col;
    int n = a[0].value;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (k <= n && a[k].row == i && a[k].col == j) {
                printf("%d ", a[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    term a[MAX_TERMS];
    term b[MAX_TERMS];
    int choice;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &a[0].row, &a[0].col);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &a[0].value);

    printf("Enter elements (row, column, value):\n");
    for (int i = 1; i <= a[0].value; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    printf("\nOriginal Matrix:\n");
    displayMatrix(a);

    printf("\nEnter choice");
    printf("\n1.Simple transpose");
    printf("\n2.Fast Transpose");
    scanf("%d",&choice);

    if(choice == 1){ 
        simpletranspose(a, b);
        printf("\nTransposed Matrix:\n");
        displayMatrix(b);
    }
    else if(choice == 2){
        fastTranspose(a,b);
        printf("\nTransposed Matrix:\n");
        displayMatrix(b);
    }
    else{
        printf("Invalid choice");
    }
    return 0;
}
