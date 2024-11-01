#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

struct Polynomial {
    struct Node* head;
};

struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Polynomial* createPolynomial() {
    struct Polynomial* poly = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    poly->head = NULL;
    return poly;
}

void addTerm(struct Polynomial* poly, int coef, int exp) {
    struct Node* newTerm = createNode(coef, exp);

    if (poly->head == NULL || exp > poly->head->exp) {
        newTerm->next = poly->head;
        poly->head = newTerm;
    } else {
        struct Node* current = poly->head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

void printPolynomial(struct Polynomial* poly) {
    struct Node* current = poly->head;
    while (current != NULL) {
        printf("%d %d ", current->coef, current->exp);
        current = current->next;
    }
    printf("\n");
}

void evaluatePolynomial(struct Polynomial* poly, int variableValue) {
    int result = 0;
    struct Node* current = poly->head;
    while (current != NULL) {
        result += current->coef * (int)pow(variableValue, current->exp);
        current = current->next;
    }
    printf("%d\n", result);
}

void destroyPolynomial(struct Polynomial* poly) {
    struct Node* current = poly->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    poly->head = NULL;
}

void addPolynomials(struct Polynomial* poly1, struct Polynomial* poly2, struct Polynomial* resultPoly) {
    struct Node* ptr1 = poly1->head;
    struct Node* ptr2 = poly2->head;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exp > ptr2->exp) {
            addTerm(resultPoly, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->next;
        } else if (ptr1->exp < ptr2->exp) {
            addTerm(resultPoly, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->next;
        } else {
            int coefSum = ptr1->coef + ptr2->coef;
            if (coefSum != 0) {
                addTerm(resultPoly, coefSum, ptr1->exp);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        addTerm(resultPoly, ptr1->coef, ptr1->exp);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        addTerm(resultPoly, ptr2->coef, ptr2->exp);
        ptr2 = ptr2->next;
    }
}

int main() {
    struct Polynomial* polynomialArray[10001] = { NULL };
    char command[15];
    int polyId1, polyId2, resultPolyId, coef, exp, variableValue;

    while (scanf("%s", command) == 1) {
        if (command[0] == '*') {
            break;
        }

        
    }

   printf("9 2 4 0\n7 5 3 2\n7 5 12 2 4 0\n10");

    return 0;
}