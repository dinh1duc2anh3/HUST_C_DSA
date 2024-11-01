           #include <stdio.h>
#include <stdlib.h>

// Định nghĩa một node trong cây nhị phân tìm kiếm
struct Node {
    int key;
    struct Node *left, *right;
};

// Hàm tạo một node mới
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Hàm thêm một node vào cây nhị phân tìm kiếm
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Hàm xóa một node từ cây nhị phân tìm kiếm
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Hàm tính khoảng cách giữa 2 nodes
int findDistance(struct Node* root, int n1, int n2) {
    if (root == NULL) return -1;

    if (n1 < root->key && n2 < root->key)
        return findDistance(root->left, n1, n2);
    else if (n1 > root->key && n2 > root->key)
        return findDistance(root->right, n1, n2);
    else
        return findDistance(root, n1) + findDistance(root, n2);
}

// Hàm tính khoảng cách từ một node đến gốc
int findDistanceFromRoot(struct Node* root, int key) {
    if (root == NULL) return -1;

    if (root->key == key) return 0;
    else if (key < root->key)
        return 1 + findDistanceFromRoot(root->left, key);
    else
        return 1 + findDistanceFromRoot(root->right, key);
}

int main() {
    struct Node* root = NULL;

    // Thêm các node vào cây nhị phân tìm kiếm
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    // Tính khoảng cách giữa 2 nodes bất kỳ
    int distance1 = findDistance(root, 4, 7);
    printf("Distance between 4 and 7 is: %d\n", distance1);

    int distance2 = findDistance(root, 1, 13);
    printf("Distance between 1 and 13 is: %d\n", distance2);

    int distance3 = findDistance(root, 3, 3);
    printf("Distance between 3 and 3 is: %d\n", distance3);

    return 0;
}
