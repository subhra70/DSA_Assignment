#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *front = NULL, *rear = NULL;

void enqueue(int item) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));  // Allocate memory

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = item;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        head = newnode;
        front = head;
        rear = head;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue() {
    int item;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = head->data;
        struct node *temp = head;
        head = head->next;
        front = head;
        if (head == NULL) {
            rear = NULL;
        }
        free(temp);
    }
    return item;
}

void display() {
    if (front == NULL) {
        printf("\nQueue is Empty.\n");
        return;
    }
    struct node *ptr = front;
    printf("\nQueue items are:\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int item, ch;
    while (1) {
        printf("\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for Exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("Deleted item is %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice!\n");
        }
    }

    return 0;
}
