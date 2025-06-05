#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void enqueue(int *queue, int *front, int *rear, int item)
{
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1))
    {
        printf("Queue is full\n");
        return;
    }
    else if (*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        queue[*rear] = item;
    }
    else if(*front!=0 && *rear==MAX-1)
    {
        *rear=0;
        queue[*rear] = item;
    }
    else
    {
        *rear = *rear + 1;
        queue[*rear] = item;
    }
}
int dequeue(int *queue, int *front, int *rear)
{
    int item;
    if ((*front == -1 && *rear == -1) || (*rear == MAX - 1 && *front == MAX))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (*front == MAX - 1 && *rear != MAX - 1)
    {
        item = queue[*front];
        *front = 0;
    }
    else
    {
        item = queue[*front];
        *front = *front + 1;
    }
    return item;
}
void display(int *queue, int front, int rear)
{
    int i = front;
    printf("\nQueue elements are:\n");
    if (rear < front)
    {
        while (i < MAX)
        {
            printf("%d ", queue[i]);
            i++;
        }
        i = 0;
        while (i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
int main()
{
    int *queue, front = -1, rear = -1, ch, item;
    queue = (int *)malloc(sizeof(int) * MAX);
    while (1)
    {
        printf("\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the item: ");
            scanf("%d", &item);
            enqueue(queue, &front, &rear, item);
            break;
        case 2:
            item = dequeue(queue, &front, &rear);
            if (item != -1)
            {
                printf("\nDeleted item is %d\n", item);
            }
            break;
        case 3:
            display(queue, front, rear);
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong choice!\n");
            break;
        }
    }

    return 0;
}