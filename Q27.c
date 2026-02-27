#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Find length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move longer list ahead
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Traverse together
    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    struct Node* head1 = newNode(10);
    head1->next = newNode(20);
    head1->next->next = newNode(30);
    head1->next->next->next = newNode(40);
    head1->next->next->next->next = newNode(50);

    struct Node* head2 = newNode(15);
    head2->next = newNode(25);
    head2->next->next = head1->next->next; // intersection at 30

    struct Node* res = findIntersection(head1, head2);

    if (res)
        printf("%d", res->data);
    else
        printf("No Intersection");

    return 0;
}