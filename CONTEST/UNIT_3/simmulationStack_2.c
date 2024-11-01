#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

Node * top;

Node* makeNode(int value){
    Node* newNode = (Node* )malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node* push (int value){
    Node* temp = makeNode(value);
    if (top == NULL){
        top = temp;
        return top;
    }

    temp->next = top;
    top = temp;
    return top;
}

Node* pop(int* result){
    if (top == NULL){
        *result = -1; // stack is empty
        return NULL;
    }

    Node* temp = top;
    *result = temp->value;
    top = top->next;
    free(temp);
    return top;
}

int main(){
    char operation[10];
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
            top = push(elementValue);
            
        } else if (
            operation[0] == 'P'
            && operation[1] == 'O'
            && operation[2] == 'P') {
            int result;
            top = pop(&result);

            if (result == -1) printf("NULL\n");
            else {
                printf("%d\n", result);
            }
        }
    }
    return 0;
}