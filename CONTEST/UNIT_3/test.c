#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

// Cấu trúc cho một nút trong danh sách liên kết đơn
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// Hàm tạo một nút mới cho DSLK
ListNode* createNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm một nút mới vào cuối DSLK
void appendToList(ListNode** head, int data) {
    ListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Hàm in ra DSLK
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* makeRoot(int u) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->id = u;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* findNode(Node* tree, int u) {
    if (tree == NULL) {
        return NULL;
    }

    if (tree->id == u) {
        return tree;
    }

    Node* leftResult = findNode(tree->left, u);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findNode(tree->right, u);
}

void addLeft(Node* tree, int u, int v) {
    Node* nodeV = findNode(tree, v);
    if (nodeV != NULL && nodeV->left == NULL) {
        Node* nodeU = findNode(tree, u);
        if (nodeU == NULL) {
            nodeV->left = makeRoot(u);
        }
    }
}

void addRight(Node* tree, int u, int v) {
    Node* nodeV = findNode(tree, v);
    if (nodeV != NULL && nodeV->right == NULL) {
        Node* nodeU = findNode(tree, u);
        if (nodeU == NULL) {
            nodeV->right = makeRoot(u);
        }
    }
}

void preOrder(Node* tree, ListNode** list) {
    if (tree != NULL) {
        appendToList(list, tree->id);
        preOrder(tree->left, list);
        preOrder(tree->right, list);
    }
}

void inOrder(Node* tree, ListNode** list) {
    if (tree != NULL) {
        inOrder(tree->left, list);
        appendToList(list, tree->id);
        inOrder(tree->right, list);
    }
}

void postOrder(Node* tree, ListNode** list) {
    if (tree != NULL) {
        postOrder(tree->left, list);
        postOrder(tree->right, list);
        appendToList(list, tree->id);
    }
}

int main() {
    Node* tree = NULL;
    char cmd[30];
    int u, v;
     int pre = 0;
     int in = 0;
     int post = 0;

     
            ListNode* preOrderList = NULL;
            
            ListNode* inOrderList = NULL;
            
            ListNode* postOrderList = NULL;
    while (scanf("%s", cmd) == 1) {
         if (cmd[0] == '*') break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            tree = makeRoot(u);
        } else if (strcmp(cmd, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            addLeft(tree, u, v);
        } else if (strcmp(cmd, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            addRight(tree, u, v);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            pre++;
            preOrder(tree, &preOrderList);
            
        } else if (strcmp(cmd, "InOrder") == 0) {
            in++;
            inOrder(tree, &inOrderList);
        } else if (strcmp(cmd, "PostOrder") == 0) {
            post++;
            postOrder(tree, &postOrderList);
        }
    }
    if (pre != 0) {
        
            printList(preOrderList);
    }
    if (in != 0) {
        
            printList(inOrderList);
    }
    if (post != 0) {
        
            printList(postOrderList);
    }
    

    free(tree);
    return 0;
}
