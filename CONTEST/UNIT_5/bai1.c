#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
    char val;
    struct Node* left;
    struct Node* right;
} Node ;

 Node* newNode(char key) {
     Node* temp = ( Node*)malloc(sizeof( Node));
    temp->val = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, char key) {
    if (root == NULL) {
        return newNode(key);
    } else {
        if (key > root->val) {
            root->right = insert(root->right, key);
        } else if (key < root->val) {
            root->left = insert(root->left, key);
        }
    }
    return root;
}

 Node* minValueNode( Node* node) {
     Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

 Node* deleteNode( Node* root, char key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
             Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
             Node* temp = root->left;
            free(root);
            return temp;
        }

         Node* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}




void postorderTraversal( Node* root) {
    if (root == NULL) {
        return;

    }
        postorderTraversal(root->right);

        postorderTraversal(root->left); 

        printf("%c ", root->val);
}

void freeTree(Node* root){
    if (root == NULL) { 
        return; 
    }
    
    freeTree(root->left); 
    
    freeTree(root->right); 
    free(root); 
}

int main() {
    Node* root = NULL;

    char command[10];
    char key;

    while (1) {
        scanf("%s", command);
        if (command[0] == '#') {
            break;
        } 
        scanf(" %c", &key); 
        if (command[0] == 'i') { 
            root = insert(root, key); 
        }
        else if (command[0] == 'd') { 
            root = deleteNode(root, key);  // Corrected function name
        }
    }
    
    if (root == NULL) { 
        printf("NULL\n"); 
    }
    else { 
        postorderTraversal(root); 
        printf("\n"); 
    }
    
    freeTree(root); 

    return 0;
}
