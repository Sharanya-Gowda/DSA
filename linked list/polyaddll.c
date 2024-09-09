#include <stdio.h>
#include <stdlib.h>

struct Node {
    float coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(float coef, int exp) {
    struct Node* newnode = malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newnode->coeff = coef;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}

void addTerm(struct Node** poly, float coef, int exp) {
    struct Node* newnode = createNode(coef, exp);

    if (*poly == NULL) {
        *poly = newnode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%fx^%d ", poly->coeff, poly->exp);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        float coef1 = (poly1 != NULL) ? poly1->coeff : 0;
        int exp1 = (poly1 != NULL) ? poly1->exp : 0;

        float coef2 = (poly2 != NULL) ? poly2->coeff : 0;
        int exp2 = (poly2 != NULL) ? poly2->exp : 0;

        if (exp1 == exp2) {
            float sumCoef = coef1 + coef2;
            addTerm(&result, sumCoef, exp1);
            if (poly1 != NULL) poly1 = poly1->next;
            if (poly2 != NULL) poly2 = poly2->next;
        } else if (exp1 > exp2) {
            addTerm(&result, coef1, exp1);
            if (poly1 != NULL) poly1 = poly1->next;
        } else {
            addTerm(&result, coef2, exp2);
            if (poly2 != NULL) poly2 = poly2->next;
        }
    }

    return result;
}


int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int t1, t2,exp;
    float coef;

    // Input for the first polynomial
    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d",&t1);

    for (int i = 0; i < t1; ++i) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%f %d", &coef, &exp);
        addTerm(&poly1, coef, exp);
    }

    // Input for the second polynomial
    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &t2);

    for (int i = 0; i < t2; ++i) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%f %d", &coef, &exp);
        addTerm(&poly2, coef, exp);
    }

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);

    printf("Sum: ");
    displayPolynomial(sum);

    return 0;
}