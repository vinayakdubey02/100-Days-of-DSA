#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    int n, value;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &value);

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    // Traversal (forward)
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}