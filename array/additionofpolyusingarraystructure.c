#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int exponent;
    float coefficient;
} Term;

Term terms[MAX];
int avail = 0;

int COMPARE(int exponentA, int exponentB) {
    if (exponentA > exponentB)
        return 1;
    else if (exponentA < exponentB)
        return -1;
    return 0;
}

void attach(float coefficient, int exponent) {
    if (avail >= MAX) {
        printf("Too many terms in the polynomial\n");
        exit(1);
    }
    terms[avail].coefficient = coefficient;
    terms[avail].exponent = exponent;
    avail++;
}

void add(int startA, int finishA, int startB, int finishB, int *startD, int *finishD) {
    int startTemp = avail;

    while (startA <= finishA && startB <= finishB) {
        switch (COMPARE(terms[startA].exponent, terms[startB].exponent)) {
            case -1:
                attach(terms[startB].coefficient, terms[startB].exponent);
                startB++;
                break;
            case 0:
                attach(terms[startA].coefficient + terms[startB].coefficient, terms[startA].exponent);
                startA++;
                startB++;
                break;
            case 1:
                attach(terms[startA].coefficient, terms[startA].exponent);
                startA++;
                break;
        }
    } 

    for (; startA <= finishA; startA++)
        attach(terms[startA].coefficient, terms[startA].exponent);

    for (; startB <= finishB; startB++)
        attach(terms[startB].coefficient, terms[startB].exponent);

    *startD = startTemp;
    *finishD = avail - 1;
}

int main() {
    int i, startA, finishA, startB, finishB, startD, finishD, exponent, t1, t2;
    float coefficient;

    printf("\nEnter the number of terms in polynomial A(x): ");
    scanf("%d", &t1);
    printf("\nEnter the coefficient and degree: ");
    for (i = 0; i < t1; i++) {
        scanf("%f %d", &coefficient, &exponent);
        attach(coefficient, exponent);
    }
    finishA = avail - 1;

    printf("\nEnter the number of terms in polynomial B(x): ");
    scanf("%d", &t2);
    printf("\nEnter the coefficient and degree: ");
    for (i = 0; i < t2; i++) {
        scanf("%f %d", &coefficient, &exponent);
        attach(coefficient, exponent);
    }
    finishB = avail - 1;

    add(0, finishA, t1, finishB, &startD, &finishD);

    printf("\nA(x): ");
    for (i = 0; i <= finishA; i++) {
        printf("%fx^%d ", terms[i].coefficient, terms[i].exponent);
        if (i != finishA)
            printf("+ ");
    }

    printf("\nB(x): ");
    for (i = t1; i <= finishB; i++) {
        printf("%fx^%d ", terms[i].coefficient, terms[i].exponent);
        if (i != finishB)
            printf("+ ");
    }

    printf("\nA(x) + B(x): ");
    for (i = startD; i <= finishD; i++) {
        printf("%fx^%d ", terms[i].coefficient, terms[i].exponent);
        if (i != finishD)
            printf("+ ");
    }

    return 0;
}
