#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;
    char command[10];
    int key;

    while (scanf("%s", command) == 1 && strcmp(command, "#") != 0) {
        if (scanf("%d", &key) != 1) {
            fprintf(stderr, "Invalid input format\n");
            return 1;
        }

        if (strcmp(command, "insert") == 0) {
            root = insert(root, key);
        } else {
            fprintf(stderr, "Invalid command: %s\n", command);
            return 1;
        }
    }

    preOrderTraversal(root);
    freeTree(root);

    return 0;
}
