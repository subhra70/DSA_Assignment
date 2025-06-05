#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void enqueue(int *queue, int *front, int *rear, int queueNo, int item) {
    int base = queueNo * MAX;
    if (*rear == MAX - 1) {
        printf("\nQueue no %d is full", queueNo);
    } else if (*front == -1 && *rear == -1) {
        *front = *rear = 0;
        queue[base + *rear] = item;
    } else {
        (*rear)++;
        queue[base + *rear] = item;
    }
}

int dequeue(int *queue, int *front, int *rear, int queueNo) {
    int base = queueNo * MAX;
    int item;
    if (*front == -1 || *front > *rear) {
        printf("\nQueue no %d is empty", queueNo);
        return -1;
    } else {
        item = queue[base + *front];
        (*front)++;
        if (*front > *rear) {
            *front = *rear = -1;
        }
    }
    return item;
}

void display(int *queue, int *front, int *rear, int queueNo) {
    int base = queueNo * MAX;
    if (*front == -1 || *front > *rear) {
        printf("\nQueue no %d is empty\n", queueNo);
        return;
    }
    printf("\nElements of queue %d are:\n", queueNo);
    for (int i = *front; i <= *rear; i++) {
        printf("%d ", queue[base + i]);
    }
    printf("\n");
}

int main() {
    int *queue, m, n, item, queueNo, *front, *rear, ch;
    printf("\nEnter the number of queues you want: ");
    scanf("%d", &m);
    n = MAX;
    queue = (int *)malloc(sizeof(int) * m * n);
    front = (int *)malloc(sizeof(int) * m);
    rear = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        front[i] = -1;
        rear[i] = -1;
    }

    while (1) {
        printf("\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for Exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the queue number (0 to %d): ", m - 1);
                scanf("%d", &queueNo);
                if (queueNo < 0 || queueNo >= m) {
                    printf("\nInvalid queue number");
                    break;
                }
                printf("Enter the item you want to insert: ");
                scanf("%d", &item);
                enqueue(queue, &front[queueNo], &rear[queueNo], queueNo, item);
                break;
            case 2:
                printf("\nEnter the queue number (0 to %d): ", m - 1);
                scanf("%d", &queueNo);
                if (queueNo < 0 || queueNo >= m) {
                    printf("\nInvalid queue number");
                    break;
                }
                item = dequeue(queue, &front[queueNo], &rear[queueNo], queueNo);
                if (item != -1) {
                    printf("\nDeleted item from queue %d is %d", queueNo, item);
                }
                break;
            case 3:
                printf("\nEnter the queue number (0 to %d): ", m - 1);
                scanf("%d", &queueNo);
                if (queueNo < 0 || queueNo >= m) {
                    printf("\nInvalid queue number");
                    break;
                }
                display(queue, &front[queueNo], &rear[queueNo], queueNo);
                break;
            case 4:
                free(queue);
                free(front);
                free(rear);
                exit(0);
            default:
                printf("\nInvalid choice");
                break;
        }
    }
}
