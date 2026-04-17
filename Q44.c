#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create new node
struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Build tree from array (level order)
struct node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct node* root = create(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);

    return root;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(struct node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(struct node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n, 0);

    // Inorder
    inorder(root);
    printf("\n");

    // Preorder
    preorder(root);
    printf("\n");

    // Postorder
    postorder(root);
    printf("\n");

    return 0;
}