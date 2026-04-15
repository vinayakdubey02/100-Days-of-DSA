#include<stdio.h>

#define N 5

int queue[N], front = -1, rear = -1;
int stack[N], top = -1;

// QUEUE ENQUEUE
void enqueue(int x)
{
    if(rear == N-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = x;
    }
}

// QUEUE DEQUEUE
int dequeue()
{
    int x;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        x = queue[front];
        front++;
        return x;
    }
}

// STACK PUSH
void push(int x)
{
    if(top == N-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

// STACK POP
int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

// REVERSE QUEUE
void reverseQueue()
{
    // Step 1: dequeue → push into stack
    while(front <= rear)
    {
        push(dequeue());
    }

    // Step 2: pop → enqueue back
    while(top != -1)
    {
        enqueue(pop());
    }
}

// DISPLAY QUEUE
void display()
{
    if(front == -1 || front > rear)
    {
        printf("Queue empty\n");
    }
    else
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// MAIN
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    printf("Original Queue:\n");
    display();

    reverseQueue();

    printf("Reversed Queue:\n");
    display();

    return 0;
}