#include<stdio.h>

#define N 100

int pq[N];
int size = 0;

// Insert element
void insert(int x)
{
    if(size == N)
    {
        printf("Overflow\n");
        return;
    }

    pq[size] = x;
    size++;
}

// Delete highest priority (smallest element)
int delete()
{
    if(size == 0)
    {
        return -1;
    }

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
        {
            minIndex = i;
        }
    }

    int value = pq[minIndex];

    // Shift elements
    for(int i = minIndex; i < size-1; i++)
    {
        pq[i] = pq[i+1];
    }

    size--;

    return value;
}

// Peek highest priority element
int peek()
{
    if(size == 0)
    {
        return -1;
    }

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
        {
            minIndex = i;
        }
    }

    return pq[minIndex];
}

// Display queue
void display()
{
    if(size == 0)
    {
        printf("Empty\n");
        return;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main()
{
    int choice, x;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                printf("Deleted: %d\n", delete());
                break;

            case 3:
                printf("Peek: %d\n", peek());
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}