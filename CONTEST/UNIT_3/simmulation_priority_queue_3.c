#include <stdio.h>
#include <stdlib.h>

int maxQueueSize = 100;

typedef struct {
    int value;
} Element;

int maxArraySize = 100;

void addLast(int **array, int *arraySize, int popValue, int *last) {
    if (*arraySize == maxArraySize) {
        maxArraySize *= 2;
        *array = (int*)realloc(*array, maxArraySize * sizeof(int));
    }

    (*array)[*last] = popValue;
    (*last)++;
    (*arraySize)++;
}

void printList(int *array, int last) {
    for (int i = 0; i < last; i++) {
        printf("%d\n", array[i]);
    }
}

void insertIntoQueue(Element **priorityQueue, int *queueSize, int elementValue) {
    int i = (*queueSize) - 1;

    // resize the priorityQueue if needed
    if (*queueSize == maxQueueSize) {
        maxQueueSize *= 2;
        *priorityQueue = (Element*)realloc(*priorityQueue, maxQueueSize * sizeof(Element));
    }

    while (i >= 0 && (*priorityQueue)[i].value > elementValue) {
        (*priorityQueue)[i + 1] = (*priorityQueue)[i];
        i--;
    }
    (*priorityQueue)[i + 1].value = elementValue;
    (*queueSize)++;
}

void popFromQueue(int *array, int *front, int *queueSize, int *last, Element *priorityQueue) {
    if (*queueSize > 0) {
        addLast(&array, queueSize, priorityQueue[*front].value, last);
        (*front)++;
        (*queueSize)--;
    }
}

int main() {
    Element *priorityQueue = NULL;
    int *array = NULL;

    int queueSize = 0;
    int arraySize = maxArraySize;
    int front = 0;
    int last = 0;
    char operation[10];

    priorityQueue = (Element *)malloc(maxQueueSize * sizeof(Element));
    array = (int *)malloc(arraySize * sizeof(int));

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
            popFromQueue(array, &front, &queueSize, &last, priorityQueue);
        }
    }

    printList(array, last);
    free(priorityQueue);
    free(array);
    return 0;
}
