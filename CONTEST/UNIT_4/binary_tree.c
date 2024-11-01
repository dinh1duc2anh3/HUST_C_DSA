#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

// Hàm tạo nút mới
Node* createNode(char id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

// Hàm thêm con trái
void addLeftChild(Node** root, char parentID, char childID) {
    if (*root == NULL) return;

    if ((*root)->id == parentID) {
        if ((*root)->leftChild == NULL) {
            (*root)->leftChild = createNode(childID);
        }
    } else {
        addLeftChild(&(*root)->leftChild, parentID, childID);
        addLeftChild(&(*root)->rightChild, parentID, childID);
    }
}

// Hàm thêm con phải
void addRightChild(Node** root, char parentID, char childID) {
    if (*root == NULL) return;

    if ((*root)->id == parentID) {
        if ((*root)->rightChild == NULL) {
            (*root)->rightChild = createNode(childID);
        }
    } else {
        addRightChild(&(*root)->leftChild, parentID, childID);
        addRightChild(&(*root)->rightChild, parentID, childID);
    }
}

// Hàm duyệt cây theo thứ tự trước
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%c ", root->id);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

// Hàm duyệt cây theo thứ tự giữa
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->leftChild);
        printf("%c ", root->id);
        inOrder(root->rightChild);
    }
}

// Hàm duyệt cây theo thứ tự sau
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%c ", root->id);
    }
}

// Hàm kiểm tra cây hoàn hảo
int isPerfect(Node* root) {
    if (root == NULL) return 1;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        return 1;
    }

    if (root->leftChild != NULL && root->rightChild != NULL) {
        return isPerfect(root->leftChild) && isPerfect(root->rightChild);
    }

    return 0;
}

// Hàm kiểm tra cây đầy đủ
int isFull(Node* root) {
    if (root == NULL) return 1;

    if ((root->leftChild == NULL && root->rightChild != NULL) ||
        (root->leftChild != NULL && root->rightChild == NULL)) {
        return 0;
    }

    return isFull(root->leftChild) && isFull(root->rightChild);
}

// Hàm kiểm tra cây hoàn chỉnh
int isComplete(Node* root, int level, int depth) {
    if (root == NULL) return 1;

    if (level >= depth) {
        return (root->leftChild == NULL && root->rightChild == NULL);
    }

    return isComplete(root->leftChild, level + 1, depth) && isComplete(root->rightChild, level + 1, depth);
}

// Hàm tính chiều cao của cây
int height(Node* root) {
    if (root == NULL) return 0;

    int leftHeight = height(root->leftChild);
    int rightHeight = height(root->rightChild);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Hàm kiểm tra cây cân bằng
int isBalanced(Node* root) {
    if (root == NULL) return 1;

    int leftHeight = height(root->leftChild);
    int rightHeight = height(root->rightChild);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->leftChild) && isBalanced(root->rightChild)) {
        return 1;
    }

    return 0;
}

int main() {
    Node* root = NULL;

    char command[20], u, v;

    do {
        scanf("%s", command);

        if (strcmp(command, "MakeRoot") == 0) {
            scanf(" %c", &u);
            root = createNode(u);
        } else if (strcmp(command, "AddLeftChild") == 0) {
            scanf(" %c %c", &u, &v);
            addLeftChild(&root, u, v);
        } else if (strcmp(command, "AddRightChild") == 0) {
            scanf(" %c %c", &u, &v);
            addRightChild(&root, u, v);
        } else if (strcmp(command, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(command, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(command, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        } else if (strcmp(command, "IsPerfect") == 0) {
            scanf(" %c", &u);
            if (isPerfect(root)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else if (strcmp(command, "IsFull") == 0) {
            scanf(" %c", &u);
            if (isFull(root)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else if (strcmp(command, "IsComplete") == 0) {
            scanf(" %c", &u);
            if (isComplete(root, 0, height(root))) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else if (strcmp(command, "IsBalanced") == 0) {
            scanf(" %c", &u);
            if (isBalanced(root)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            // Xử lý lựa chọn không hợp lệ
            printf("Invalid command\n");
        }

    } while (strcmp(command, "#") != 0);

    return 0;
}