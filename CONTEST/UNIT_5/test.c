#include <stdio.h>
#include <stdlib.h>

struct Node {
    char key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
    return root;
}

struct Node* deleteNode(struct Node* root, char key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* minimum = root->right;
        while (minimum->left != NULL) {
            minimum = minimum->left;
        }
        root->key = minimum->key;
        root->right = deleteNode(root->right, minimum->key);
    }
    return root;
}

void printRightView(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->key);
    if (root->right) {
        printRightView(root->right);
    }
    else {
        printRightView(root->left);
    }
}

int main() {
    struct Node* root = NULL;

    while (1) {
        int choice;
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print Right View\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char key;
            printf("Enter key to insert: ");
            scanf(" %c", &key);
            root = insert(root, key);
        }
        else if (choice == 2) {
            char key;
            printf("Enter key to delete: ");
            scanf(" %c", &key);
            root = deleteNode(root, key);
        }
        else if (choice == 3) {
            printf("Right View: ");
            printRightView(root);
            printf("\n");
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}