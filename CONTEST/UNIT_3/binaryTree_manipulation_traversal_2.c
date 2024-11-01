#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

//------------------------------------------------------------
        // Cấu trúc cho một nút trong danh sách liên kết đơn
        typedef struct ListNode {
            int data;
            struct ListNode* next;
        } ListNode;

        ListNode* head = NULL , *last = NULL;

        // Hàm tạo một nút mới cho DSLK
        ListNode* makeNode(int data) {
            ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
            newNode->data = data;
            newNode->next = NULL;
            return newNode;
        }

        void addLast(int data){
            ListNode* newNode = makeNode(data);
            if (head == NULL){
                head = newNode;
                last = newNode;
            }
            else {
                last->next = newNode;
                last= newNode;

            }
        }

        void printList() {
            ListNode* p = head;
            while (p != NULL) {
                if (p->data == -1 ) printf("\n");
                else {
                    printf("%d ", p->data);
                }
                
                p = p->next;
            }
        }

        void freeList(){
            ListNode* current = head;
            ListNode* next;
            while (current != NULL){
                next = current->next;
                free(current);
                current = next;

            }
        }


//------------------------------------------------------------
Node* tree = NULL;

Node* makeRoot(int u ){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->id = u;
    temp->left = NULL;
    temp->right = NULL;
    return temp;

}

Node* findNode(Node* tree, int u){
    if (tree == NULL) return NULL;

    if (tree->id == u) return tree;

    Node* leftResult = findNode(tree->left, u);
    if (leftResult != NULL) return leftResult;
    return findNode(tree->right, u);

}

void addLeft (int u, int v){
    Node* nodeV = findNode(tree, v);
    if (nodeV != NULL && nodeV->left == NULL){
        Node* nodeU = findNode(tree, u);
        if (nodeU == NULL){
            nodeV->left = makeRoot(u);
        }
    } 
}

void addRight(int u , int v){
    Node* nodeV = findNode(tree, v);
    if (nodeV != NULL && nodeV->right == NULL){
        Node* nodeU = findNode(tree, u);
        if (nodeU == NULL){
            nodeV->right = makeRoot(u);
        }
    } 
}

void preOrder(Node* tree){
    if (tree != NULL){
        addLast(tree->id);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(Node* tree){
    if (tree != NULL){
        inOrder(tree->left);
        addLast(tree->id);
        inOrder(tree->right);
    }
}

void postOrder(Node* tree){
    if (tree != NULL){
        postOrder(tree->left);
        postOrder(tree->right);
        addLast(tree->id);
    }
}

void freeTree(Node* tree) {
    if (tree != NULL) {
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
    }
}



int main(){
    char cmd[30];
    int u, v;
    while (scanf("%s", cmd) == 1) {
         if (cmd[0] == '*') break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            tree = makeRoot(u);
        } else if (strcmp(cmd, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            addLeft(u, v);
        } else if (strcmp(cmd, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            addRight(u, v);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            preOrder(tree);
            addLast(-1);
            
        } else if (strcmp(cmd, "InOrder") == 0) {
            inOrder(tree);
            addLast(-1);
        } else if (strcmp(cmd, "PostOrder") == 0) {
            postOrder(tree);
            addLast(-1);
        }
    }
    printList();
    freeList();
    freeTree(tree);
    return 0;
}