#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo ra 1 node
Node* createNode(int data) {
    // Cấp phát bộ nhớ
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Chèn 1 nút vào cây
Node* insertNode(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

// Duyệt cây theo phương pháp tiền thứ tự
void preorderTraversal(Node* node) {
    if (node != NULL) {
        printf("%d\t", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Trung thứ tự
void inOrderNode(Node* node) {
    if (node != NULL) {
        inOrderNode(node->left);
        printf("%d\t", node->data);
        inOrderNode(node->right);
    }
}

// Hậu thứ tự
void postOrderNode(Node* node) {
    if (node != NULL) {
        postOrderNode(node->left);
        postOrderNode(node->right);
        printf("%d\t", node->data);
    }
}

int main() {
    Node* tree = NULL;
    int n, data;

    printf("Nhap so luong phan tu cua cay: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &data);
        tree = insertNode(tree, data);
    }

    printf("\nDuyet cay theo tien thu tu: \n");
    preorderTraversal(tree);
    printf("\n");

    printf("Duyet cay theo trung thu tu: \n");
    inOrderNode(tree);
    printf("\n");

    printf("Duyet cay theo hau thu tu: \n");
    postOrderNode(tree);
    printf("\n");

    return 0;
}
