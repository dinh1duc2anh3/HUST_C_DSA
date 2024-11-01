#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

//phien ban khong in ra output o cuoi chuong trinh ma in ra ngay khi nhan preorder, inorder, postorder

typedef struct Node{
    int id;
    struct Node* left;
    struct Node* right;
} Node;


Node* makeRoot(int u){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->id = u;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* findNode(Node* tree, int u){
    if (tree == NULL){
        return NULL;
    }

    if (tree->id == u){
        return tree;
    }

    Node* leftResult = findNode(tree->left,u);
    if (leftResult != NULL){
        return leftResult;
    }
    return findNode(tree->right,u);
}

void addLeft(Node* tree, int u, int v){
    Node* nodeV = findNode(tree,v);
    if (nodeV != NULL && nodeV->left == NULL ){
        Node* nodeU = findNode(tree,u);
        if (nodeU == NULL) {
            nodeV->left = makeRoot(u);
        }
    }

}

void addRight(Node* tree, int u, int v){
    Node* nodeV = findNode(tree,v);
    if (nodeV != NULL && nodeV->right == NULL ){
        Node* nodeU = findNode(tree,u);
        if (nodeU == NULL) {
            nodeV->right = makeRoot(u);
        }
    }

}



void preOrder(Node* tree){
    if (tree != NULL){
        printf("%d ",tree->id);
        preOrder(tree->left);
        preOrder(tree->right);
    } 

}   

void inOrder(Node* tree){
    if (tree != NULL){
        inOrder(tree->left);
        printf("%d ",tree->id);
        inOrder(tree->right);

    }
}

void postOrder(Node* tree){
    if (tree != NULL){
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ",tree->id);
    }
}

void freeTree(Node* tree){
    while ( tree != NULL){
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
    }
}

int main(){
    Node* tree = NULL;
    char cmd[SIZE];
    int u,v;
    int pre = 0,in = 0,post = 0;
    while ((scanf("%s",cmd)== 1)){
        if (cmd[0] == '*') break;
        else if (strcmp(cmd,"MakeRoot") == 0){
            scanf("%d",&u);
            tree = makeRoot(u);
        }
        else if (strcmp(cmd,"AddLeft") == 0){
            scanf("%d %d", &u, &v);
            addLeft(tree, u, v);
        }
        else if (strcmp(cmd,"AddRight") == 0){
            scanf("%d %d", &u, &v);
            addRight(tree, u, v);
        }
        else if (strcmp(cmd,"PreOrder") == 0){
            preOrder(tree);
            printf("\n");
        }
        else if (strcmp(cmd,"InOrder") == 0){
            inOrder(tree);
            printf("\n");
        }
        else if (strcmp(cmd,"PostOrder") == 0){
            postOrder(tree);
            printf("\n");
        }
        
    }
    
    freeTree(tree);
    return 0;   
}

