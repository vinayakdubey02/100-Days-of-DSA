#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};


struct Node* createNode(int c, int e) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}


struct Node* insertEnd(struct Node* head, int c, int e) {
    struct Node* temp = createNode(c, e);

    if (head == NULL)
        return temp;

    struct Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return head;
}


void display(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->exp == 0)
            printf("%d", curr->coeff);
        else if (curr->exp == 1)
            printf("%dx", curr->coeff);
        else
            printf("%dx^%d", curr->coeff, curr->exp);

        if (curr->next != NULL)
            printf(" + ");

        curr = curr->next;
    }
}

int main() {
    int n, c, e;
    struct Node* head = NULL;

    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insertEnd(head, c, e);
    }

    
    display(head);

    return 0;
}