#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// dslk don

typedef struct Node{
    int key;
    struct Node* next;
} Node;

Node* head;
Node* last;

Node* makeNode(int k){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = k;
    newNode->next = NULL;
    return newNode;
}

Node* addLast(int k){
    Node* newNode = makeNode(k);
    if (head == NULL) {
        head = newNode; 
        last = newNode;
        return head;
    }

    Node* p = head;
    //check if k value has appeared before
    while (p->next != NULL){
        if (p->key == k) {
            free(newNode);
            return NULL;}
        p = p->next;
    }
    if (p->key == k) {
        free(newNode);
        return NULL;
    }

    else {
        last->next = newNode;
        last = newNode;
    }
    return head;
}

Node* addFirst(int k){
    Node * newNode = makeNode(k);
    if (head == NULL) {
        head = newNode;
        last = newNode;
        return head;
    }
    Node* p = head;
    while (p != NULL){
        if (p->key == k) {
            free(newNode);
            return NULL;
        }
        p = p->next;
    }

    
    newNode->next = head;
    head = newNode;
    return head;
}

Node* addAfter(int u, int v){ //add node->key = u after node->key = v
    if (head == NULL) return NULL;
    
    Node * p = head;
    
    // check if u value has appeared before
    while (p !=  NULL) {
        if (p->key == u) {
            return NULL;
            } //Instead of return NULL,pls Free allocated memory if duplicate key
        p = p->next;
    }
    
    p = head;
    while (p != NULL){
        if (p->key == v) {
            Node* temp = makeNode(u);
            temp->next = p->next;
            p->next = temp;

            if (p == last) last = temp;

            break;
        }
        else 
            {p = p->next;}
    }
    return head;
}

Node* addBefore(int u,int v){//add node->key = u before node->key = v
    if (head == NULL) return NULL;
    
    Node * p = head;
    while (p !=  NULL) {
        if (p->key == u) {
           // Free allocated memory if duplicate key
            return NULL;
        }
        p = p->next;
    }
    
    p = head;
    Node* prev = NULL;

    while (p != NULL){
        
        if (p->key == v) {
            Node* temp = makeNode(u);
            
            if (prev == NULL){
                temp->next = head;
                head = temp;
            }
            else {
                temp->next = p;
                prev->next = temp;
            }
            break;
        }
        else {
             prev = p;
             p = p->next;
        }
     }
    return head;
}

Node* removeNode(int k){
    if (head == NULL) return NULL;

    Node* p = head;
    Node* prev = NULL;
    while (p != NULL){
        if (p->key == k){ /*xuat phat ;la prev = null vaf if prev = null nghia la phan
        tu dang xet la phan tu head*/
            if (prev == NULL){
                head = p->next;
                break;
            }
            else {
                if (p == last) last = prev;
                prev->next = p->next;
            }
            if (p == last) last = prev;
            prev->next = p->next;
            free(p);
            break;
        }
        else {
            prev = p;
            p = p->next ;// prev = p thay vi prev = prev->next;
        }
    }
    
   return head;
}
//ham reverse cu
// Node* reverse(Node** head){
//     Node** prev = NULL;
//     Node** current = head;
//     Node** next;

//     while( current != NULL ){
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     head = prev;
//     return head;
// }

//ham reverse 
Node* reverse(Node** head, Node** last) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    *last = current;  // Update the last pointer
    return *head;
}



void printList(){
    Node* p = head;
    while (p != NULL ){
        printf("%d ",p->key);
        p = p->next;
    }
    printf("\n");
}

void freeList(){
    Node* current = head;
    Node* next;
    while (current != NULL){
        next = current-> next;
        free(current);
        current = next;
    }
}


int main(){
    int n;
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++){
        int key;
        scanf("%d",&key);
        addLast(key);
    }


    char cmd[50];
    while (scanf("%s", cmd) == 1){
        if (cmd[0] == '#'){
            break;
        }

        int u,v;
        if (strcmp(cmd, "addlast") == 0) {
            scanf("%d", &u);
            addLast(u);
        }

        if (strcmp(cmd, "addfirst") == 0){
            scanf("%d",&u);
            addFirst(u);
        }
        if (strcmp(cmd, "addafter") == 0){
            scanf("%d %d",&u,&v);
            addAfter(u,v);
        }
        if (strcmp(cmd, "addbefore") == 0){
            scanf("%d %d",&u,&v);
            addBefore(u,v);
        }
        if (strcmp(cmd, "remove") == 0){
            scanf("%d",&u);
            removeNode(u);
        }
        if (strcmp(cmd, "reverse") == 0){
            reverse(&head,&last);
        }
        
    }
    printList();
    
    freeList();

    return 0;   
}
