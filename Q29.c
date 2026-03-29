#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n,k;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*newNode;


    for(int i=0;i<n;i++)
    {
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }

    scanf("%d",&k);

    
    int count=1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }


    temp->next=head;

    
    k = k % count;
    int steps = count - k;

    temp=head;
    for(int i=1;i<steps;i++)
        temp=temp->next;

    head=temp->next;

    
    temp->next=NULL;

    
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}