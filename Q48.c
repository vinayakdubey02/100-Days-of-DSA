#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create node
struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Build tree from level order array
struct node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct node* root = create(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Count leaf nodes
int countLeaf(struct node* root) {
    if (root == NULL)
        return 0;

    // Leaf node condition
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n, 0);

    printf("%d\n", countLeaf(root));

    return 0;
}