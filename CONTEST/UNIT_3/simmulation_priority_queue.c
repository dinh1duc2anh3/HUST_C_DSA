#include <stdio.h>
#include <stdlib.h>


int maxQueueSize = 100;

typedef struct {
    int value;
} Element;

typedef struct Node{
    int value;
    struct Node* next;
} Node;

Node* head;
Node* last;

void printList(){
    Node* p = head;
    while (p!= NULL){
        printf("%d\n",p->value);
        p = p->next;
    }
}

Node* makeNode(int k){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = k;
    temp->next = NULL;
    return temp;
}

Node* addLast(int k){
    Node* newNode = makeNode(k);
    if (head == NULL){
        head = newNode;
        last = newNode;
    }
    else {
        last->next = newNode;
        last = newNode;
    }
    return head;
}

void freeList(){
    Node* current = head;
    Node* next;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

void insertIntoQueue(Element **priorityQueue, int *queueSize, int elementValue);

/*
void insertIntoQueue(Element * priorityQueue, int * queueSize, int elementValue){
    int i = (*queueSize) - 1;

    if (*queueSize == maxQueueSize ){
        maxQueueSize ++;
        priorityQueue =(Element*)realloc(priorityQueue, maxQueueSize * sizeof(Element));
    }

    while ( i >= 0 && priorityQueue[i].value > elementValue  ) // đọc khi nào dùng . , lúc nào dùng -> 
    {
        priorityQueue[i+1] = priorityQueue[i];
        i--;
    }

    priorityQueue[i+1].value = elementValue;
    (*queueSize)++;

}
*/

void insertIntoQueue(Element **priorityQueue, int *queueSize, int elementValue) {
    int i = (*queueSize) - 1;

    if (*queueSize == maxQueueSize) {
        maxQueueSize *= 2;  // Double the size for resizing
        *priorityQueue = (Element*)realloc(*priorityQueue, maxQueueSize * sizeof(Element));
        if (*priorityQueue == NULL) {
            // Handle memory allocation failure
            exit(EXIT_FAILURE);
        }
    }

    while (i >= 0 && (*priorityQueue)[i].value > elementValue) {
        (*priorityQueue)[i + 1] = (*priorityQueue)[i];
        i--;
    }

    (*priorityQueue)[i + 1].value = elementValue;
    (*queueSize)++;
}



int main(){
    Element *priorityQueue = NULL;
    int queueSize = 0;
    char operation[5];

    priorityQueue =(Element*)malloc(maxQueueSize * sizeof(Element));

    while (1){
        scanf("%s",operation);

        if (operation[0] == '#'){
            break;
        }
        else if (
            operation[0] == 'P' 
            && operation[1] == 'U' 
            && operation[2] == 'S' 
            && operation[3] == 'H') 
            {
                int elementValue;
                scanf("%d",&elementValue);
                


                // insertIntoQueue(priorityQueue, &queueSize, elementValue);
                insertIntoQueue(&priorityQueue, &queueSize, elementValue);

            }
        else if (
            operation[0] == 'P' 
            && operation[1] == 'O' 
            && operation[2] == 'P'){
                
                if (queueSize > 0){
                    addLast(priorityQueue[0].value);

                    for (int i = 0; i < queueSize-1; i++){
                        priorityQueue[i] = priorityQueue[i+1] ;
                    }
                    
                    (queueSize) --;
                }

            }
             
     }
    printList();
        
    freeList();
    
    free(priorityQueue);
    return 0;
}