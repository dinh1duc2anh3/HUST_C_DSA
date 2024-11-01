#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *children;
    struct Node *next;
};

struct Node *createNode(const char *name) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->children = NULL;
    newNode->next = NULL;
    return newNode;
}

void addChild(struct Node *parent, const char *childName) {
    struct Node *newChild = createNode(childName);

    if (parent->children == NULL) {
        parent->children = newChild;
    } else {
        struct Node *current = parent->children;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newChild;
    }
}

void findChildren(struct Node *parent) {
    struct Node *current = parent->children;
    printf("Children of %s: ", parent->name);
    while (current != NULL) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

void printFamily(struct Node *root) {
    if (root != NULL) {
        printf("%s ", root->name);
        printFamily(root->children);
        printFamily(root->next);
    }
}

int height(struct Node *root, const char *targetName, int currentHeight) {
    if (root == NULL) {
        return 0;
    } else if (strcmp(root->name, targetName) == 0) {
        printf("Found %s having height = %d\n", targetName, currentHeight);
        return currentHeight;
    } else {
        int childHeight = height(root->children, targetName, currentHeight + 1);
        int siblingHeight = height(root->next, targetName, currentHeight);
        return childHeight > siblingHeight ? childHeight : siblingHeight;
    }
}

void freeNode(struct Node *root) {
    if (root != NULL) {
        freeNode(root->children);
        freeNode(root->next);
        printf("free node %s\n", root->name);
        free(root);
    }
}

int main() {
    struct Node *familyTree = NULL;
    char command[50];

    do {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "Load") == 0) {
            char name[50];
            scanf("%s", name);
            while (strcmp(name, "$$") != 0) {
                if (familyTree == NULL) {
                    familyTree = createNode(name);
                } else {
                    addChild(familyTree, name);
                }
                scanf("%s", name);
            }
        } else if (strcmp(command, "Height") == 0) {
            char targetName[50];
            scanf("%s", targetName);
            height(familyTree, targetName, 1);
        } else if (strcmp(command, "Quit") == 0) {
            freeNode(familyTree);
        }

    } while (strcmp(command, "Quit") != 0);

    return 0;
}
