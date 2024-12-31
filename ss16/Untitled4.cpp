#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Lo cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int search(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void searchAndPrint(Node* root, int value) {
    if (search(root, value)) {
        printf("Tim thay gia tri %d trong cay.\n", value);
    } else {
        printf("Khong tim thay gia tri %d trong cay.\n", value);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Nhap so luong phan tu cua cay: ");
    scanf("%d", &n);

    printf("Nhap cac gia tri cua cay:\n");
    for (int i = 0; i < n; i++) {
        printf("Gia tri %d: ", i + 1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nNhap gia tri can tim: ");
    scanf("%d", &value);
    searchAndPrint(root, value);

    freeTree(root);
    return 0;
}
