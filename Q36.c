#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if((rear + 1) % MAX == front)
    {
        printf("Queue Full\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    int i = front;

    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int n, m, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Enter number of dequeues: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
        dequeue();

    printf("Queue after operations:\n");
    display();

    return 0;
}