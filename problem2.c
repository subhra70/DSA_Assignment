#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int ptr = 0;
        while (ptr < size - i - 1)
        {
            if (arr[ptr] > arr[ptr + 1])
            {
                int temp = arr[ptr];
                arr[ptr] = arr[ptr + 1];
                arr[ptr + 1] = temp;
            }
            ptr++;
        }
    }
}
void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = arr[i], loc = i;
        for (int j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                loc = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[loc];
        arr[loc] = temp;
    }
}
void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i], ptr = i - 1;
        while (ptr >= 0 && temp < arr[ptr])
        {
            arr[ptr + 1] = arr[ptr];
            ptr--;
        }
        arr[ptr + 1] = temp;
    }
}
void display(int *arr, int size)
{
    printf("\nArray is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void shuffle(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int pos = rand() % size;
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}
int main()
{
    int size, *arr, ch, item;
    printf("\nEnter the size of the array:");
    scanf("%d", &size);
    arr = (int *)malloc(sizeof(int) * size);
    printf("\nEnter the elements one by one:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (arr + i));
    }
    while (1)
    {
        printf("\n1 Bubble Sort\n2 Selection Sort\n3 Insertion Sort\n4 Display Array\n5 Shuffle\n6 Exit\nYour Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            bubbleSort(arr, size);
            break;
        case 2:
            selectionSort(arr, size);
            break;
        case 3:
            insertionSort(arr, size);
            break;
        case 4:
            display(arr, size);
            break;
        case 5:
            shuffle(arr, size);
            break;
        case 6:
            exit(0);
        default:
            printf("\nWrong Choice!");
        }
    }
}