#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

typedef struct Node {
    char name[MAX_LEN];
    float grade;
    struct Node* previous;
    struct Node* next;
} Node;

Node* head = NULL;
Node *last = NULL;

void printList(){
    Node* p = head;
    while (p != NULL){
        printf("%s ",p->name);
        p = p->next;
    }
    printf("\n");
}

Node* insertNode(Node* head, char name[MAX_LEN], float grade){
    Node* newNode = (Node*) malloc(sizeof(Node ));
    strcpy(newNode->name , name);
    newNode->grade = grade;
    newNode->next = NULL;
    newNode->previous = NULL;

    if (head == NULL){
        head = newNode;
        last = newNode;
        return head;
    }

    last->next = newNode;
    newNode->previous = last;
    last = newNode;
    return head;
}




void swapNode(Node* a, Node* b){//doi grade va doi ten
    float tempGrade = a->grade;
    a->grade = b->grade;
    b->grade = tempGrade;

    char tempName[MAX_LEN] ;
    strcpy(tempName , a->name);
    strcpy(a->name , b->name);
    strcpy(b->name , tempName);

}

void selectionSort(){
    Node* p = head;
    while ( p != NULL){
        Node* minNode = p;
        Node* temp = p->next;
        while (temp != NULL){
            if (temp->grade < minNode->grade){
                minNode = temp;
            }
            temp = temp->next;
        }
        swapNode( minNode , p);
        p = p->next;
    }
}

void insertionSort(){
    Node* current = head;
    while (current != NULL){
        Node* key = current-> next;
        while (key->previous != NULL && key->grade < key->previous->grade){
            swapNode(key, key->previous);
            key = key->previous;
        }
        current = current->next;
    }
}

void bubbleSort(){
    Node* current = head;
    while ( current != NULL){
        Node* temp = last;
        while (temp != current) {
            if (temp->grade < temp->previous->grade ){
                swapNode( temp , temp->previous );
            }
            temp = temp->previous;
        }
        current= current->next;
    }
}

void freeList(){
    Node* current = head;
    Node* next;
    while ( current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

int main(){
    char name[MAX_LEN];
    float grade;
    while (1){
        scanf("%s %f",name,&grade);
        if ( name[0] == '#') {
            break;
        }

        if ( grade >= 0 && grade <= 10){
            insertNode(head,name,grade);
        }
    }
    
    char cmd[20];
    printList(head);
    scanf("%s",cmd) ;
        if (strcmp( cmd, "SelectionSort"  ) == 0) selectionSort();
        else if (strcmp( cmd, "InsertionSort"  ) == 0) insertionSort();
        else if (strcmp( cmd, "BubbleSort"  ) == 0) bubbleSort();
        else {
            printf("Wrong Command\n");
            return 1;
        }

    printList();
    freeList();
    return 0;
}