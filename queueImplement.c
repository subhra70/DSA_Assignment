#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void enqueue(int *queue, int *rear, int *front, int item)
{
    if (*rear == MAX - 1)
    {
        printf("\nQueue is full");
    }
    else if (*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        queue[*rear] = item;
    }
    else
    {
        *rear += 1;
        queue[*rear] = item;
    }
}
int dequeue(int *queue, int *rear, int *front)
{
    int item;
    if ((*front == -1 && *rear == -1) || (*rear == MAX - 1 && *front == MAX))
    {
        printf("\nQueue is empty");
        return -1;
    }
    else
    {
        item = queue[*front];
        *front += 1;
    }
    return item;
}
void display(int *queue, int *rear, int *front)
{
    printf("Queue elements are:\n");
    for (int i = *front; i <= *rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    int *queue, ch, front = -1, rear = -1, item;
    queue = (int *)malloc(sizeof(int) * MAX);
    while (1)
    {
        printf("\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for Exit\nEnter Your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the item:");
            scanf("%d", &item);
            enqueue(queue, &rear, &front, item);
            break;
        case 2:
            item = dequeue(queue, &rear, &front);
            if (item != -1)
            {
                printf("\nDeleted item is %d", item);
            }
            break;
        case 3:
            display(queue, &rear, &front);
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong Choice!\n");
            break;
        }
    }
}