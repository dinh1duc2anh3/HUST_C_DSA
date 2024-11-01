#include <stdio.h>
#include <stdlib.h>

int maxQueueSize = 100;

typedef struct {
    int value;
} Element;


//--------------------------------------------------------------------------

//dùng dslk đơn để in ra

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
//--------------------------------------------------------------------------
void insertIntoQueue(Element **priorityQueue, int *queueSize, int elementValue) {
    int i = (*queueSize) - 1;

    if (*queueSize == maxQueueSize) {
        maxQueueSize *= 2;  // Double the size for resizing
        *priorityQueue = (Element*)realloc(*priorityQueue, maxQueueSize * sizeof(Element));
    }

    while (i >= 0 && (*priorityQueue)[i].value > elementValue) {
        (*priorityQueue)[i + 1] = (*priorityQueue)[i];
        i--;
    }

    (*priorityQueue)[i + 1].value = elementValue;
    (*queueSize)++;
}

void popFromQueue(Element *priorityQueue, int *front, int *queueSize) {
    if (*queueSize > 0) {
        addLast(priorityQueue[*front].value);
        (*front)++;
        (*queueSize)--;
    }
}

int main() {
    Element *priorityQueue = NULL;
    int queueSize = 0;
    int front = 0;  // Index to keep track of the front of the queue
    char operation[5];

    priorityQueue = (Element*)malloc(maxQueueSize * sizeof(Element));

    while (1) {
        scanf("%s", operation);

        if (operation[0] == '#') {
            break;
        } else if (
            operation[0] == 'P'
            && operation[1] == 'U'
            && operation[2] == 'S'
            && operation[3] == 'H') {
            int elementValue;
            scanf("%d", &elementValue);

            insertIntoQueue(&priorityQueue, &queueSize, elementValue);
        } else if (
            operation[0] == 'P'
            && operation[1] == 'O'
            && operation[2] == 'P') {
            popFromQueue(priorityQueue, &front, &queueSize);
        }
    }

    printList();

    freeList();

    free(priorityQueue);
    return 0;
}
