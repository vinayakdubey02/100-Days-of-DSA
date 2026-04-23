#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create(int x)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node* insert(struct node* root, int x)
{
    if(root == NULL)
    {
        return create(x);
    }

    if(x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else if(x > root->data)
    {
        root->right = insert(root->right, x);
    }

    return root;
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;
    int n, x, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}