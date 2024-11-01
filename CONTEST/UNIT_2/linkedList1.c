#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* head;
Node* last,*temp;

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* next ;

    while (current->next != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return current;
}

int isPalindrome(Node* head){
    if (head == NULL || (head ->next  == NULL)) return 1;

    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node * p = head;
    Node* reverseAfterPart = reverseList(slow);

    while (reverseAfterPart != NULL){
        if (reverseAfterPart->data != p->data ) return 0;
        else {
            p = p->next;
            reverseAfterPart = reverseAfterPart->next;
        }
        return 1;

    }
}

int main(){
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        temp = (Node*)malloc(sizeof(Node));
        scanf("%d",&temp->data);
        temp->next = NULL;

        if (head == NULL){
            head = temp;
            last = temp;
        }
        else {
            last->next = temp;
            last = temp;
        }
    }

    if (isPalindrome(head)) printf("1");
    else printf("0");
    free(head);
    return 0;
}