#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500
#define STACK_LIMIT 500

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack){
    stack->top = -1;
}

int isFull(Stack* stack){
    return (stack->top == MAX_SIZE - 1);
}

int isEmpty(Stack* stack){
    return stack->top == -1;

}

void push(Stack* stack, char value){
    if (!isFull(stack)){
        stack->data[++stack->top] = value; //+ top truoc roi moi thuc hien
    }
}

char pop(Stack* stack){
    if (!isEmpty(stack)){
        return stack->data[stack->top--]; //thuc hien truoc roi moi -- top
    }
    return '\0'; // tra ve null neu stack rong
}

void inputString(char *str){
    fgets(str, STACK_LIMIT , stdin);
}

void printReversedString(Stack* stack){
    while (!isEmpty(stack)){
        printf("%c",pop(stack));
    }
    printf("\n");
}

int main(){
    Stack myStack;
    initializeStack(&myStack);

    char input[STACK_LIMIT];
    inputString(input);

    for (int i= 0; i < STACK_LIMIT && input[i] != '\0' ; i++){
        if (input[i] == '\n'){
            break;
        }
        if (isFull(&myStack)){
            printf("2");
            return 0;
        }
        push(&myStack,input[i]);
    }

    if (isEmpty(&myStack)) printf("1");
    else printReversedString(&myStack);
}