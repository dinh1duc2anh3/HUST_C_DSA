#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int value;
} Element;

int maxArraySize = 100;
int maxQueueSize = 100;
//-----------------------------------------------------------------------
 //stack dung array : khó dùng , chuyển sang dùng dslk


//-----------------------------------------------------------------------
//dung array de in output

    void addLast(int ** array, int * arraySize, int *last, int value){

        //resize the output array if needed
        if (*arraySize == maxArraySize){
            maxArraySize *= 2;
            *array = (int*)realloc(array,maxArraySize * sizeof(int));

        }

        (*array)[*last] = value;
        (*last) ++;
        (*arraySize)++;
    }   

    void printList(int * array, int arraySize){
        for (int i = 0;i < arraySize; i ++){
            printf("%d\n",array[i]);
        }
    }



//-----------------------------------------------------------------------

    void insertIntoQueue(Element ** priorityQueue, int* queueSize, int* last, int elementValue){

        //resize the priority queue if needed
        if (*queueSize == maxQueueSize) {
            maxQueueSize *= 2;
            *priorityQueue = (Element *)realloc(priorityQueue, maxQueueSize* sizeof(int));
        }

        if (*queueSize == 0){
            *last = 0;
            (*priorityQueue)[*last].value = elementValue;
            (*queueSize)++;
            return;
        }
        else {
            (*last)++;
            (*queueSize)++;
            (*priorityQueue)[*last].value = elementValue;
        }
        
    }

    void popFromQueue(int* array,int* arraySize , int *front, int* queueSize, int* last, Element * priorityQueue){
        if (*queueSize > 0){
            addLast(&array , arraySize, last, priorityQueue[*front].value );
            (*front)++;
            (*queueSize)--;

            if (*queueSize == 0) {
                free(priorityQueue);
                priorityQueue = NULL;
            }
        }


    }


//-----------------------------------------------------------------------

int main(){
    Element* priorityQueue = NULL;
    int *array = NULL;

    int queueSize = 0;
    int arraySize = maxArraySize;
    int front = 0;
    int lastQueue = 0;
    int lastArray = 0;
    char operation[20];

    priorityQueue = (Element*)malloc(maxQueueSize * sizeof(Element));
    array = (int*)malloc(maxArraySize* sizeof(int));

    while (1){
        scanf("%s",operation);

        if (operation[0] == '#'){
            break;
        } else if (
            operation[0] == 'P'
            && operation[1] == 'U'
            && operation[2] == 'S'
            && operation[3] == 'H') {
            int elementValue;
            scanf("%d", &elementValue);

            insertIntoQueue(&priorityQueue, &queueSize , &lastQueue , elementValue);
        } else if (
            operation[0] == 'P'
            && operation[1] == 'O'
            && operation[2] == 'P') {
            popFromQueue(array , &arraySize , &front , &queueSize , &lastArray , priorityQueue);
        }
    }

    printList(array, lastArray);

    free(priorityQueue);
    free(array);
    
    return 0;
}