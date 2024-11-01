#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head;
Node* last;

void printList() {
    Node* p = head;
    while (p != NULL) {
        printf("%d\n", p->value);
        p = p->next;
    }
}

Node* makeNode(int k) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = k;
    temp->next = NULL;
    return temp;
}

Node* addLast(int k) {
    Node* newNode = makeNode(k);
    if (head == NULL) {
        head = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    return head;
}

void freeList() {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int findMaxSegment(int arr[], int start, int end) {
    int max_val = arr[start];
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int main() {
    int n;
    scanf("%d", &n);

    int* sequence =(int*)malloc(n*sizeof(int));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
        sum += sequence[i];
    }

    char query[20];
    int start, end;

    while (1){
        scanf("%s", query);
         
        if (strcmp(query, "***") == 0) {
            break;
        }

        if (strcmp(query , "find-max") == 0){
            int max_val = sequence[0];
            for (int i = 1; i < n; i++) {
                if (sequence[i] > max_val) {
                    max_val = sequence[i];
                }
            }
            addLast(max_val);
        }
        else if (strcmp(query, "find-min") == 0){
            int min_val = sequence[0];
            for (int i = 1; i < n; i++) {
                if (sequence[i] < min_val) {
                    min_val = sequence[i];
                }
            }
            addLast(min_val);
        }
        else if (strcmp(query, "find-max-segment") == 0) {
            scanf("%d %d", &start, &end);
            addLast(findMaxSegment(sequence, start - 1, end - 1));
        } 
        else if (strcmp(query, "sum") == 0) {
            addLast(sum);
        }

    }
    printList();
    freeList();
    return 0;
}