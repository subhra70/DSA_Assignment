#include <stdio.h>
#include <stdlib.h>
void iterativeLSearch(int *arr, int item, int size)
{
    int loc = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            loc = i;
            break;
        }
    }
    if (loc == -1)
    {
        printf("%d not present\n", item);
    }
    else
    {
        printf("%d found at location %d\n", item, loc);
    }
}
void recursiveLSearch(int *arr, int item, int idx, int size)
{
    if (idx == size)
    {
        printf("Item not found\n");
        return;
    }
    if (arr[idx] == item)
    {
        printf("%d found at location %d\n", item, idx);
        return;
    }
    else
    {
        recursiveLSearch(arr, item, idx + 1, size);
    }
}
void iterativeBSearch(int *arr, int beg, int end, int item)
{
    int mid = (beg + end) / 2;
    while (arr[mid] != item && beg <= end)
    {
        if (arr[mid] < item)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (beg + end) / 2;
    }
    if (arr[mid] == item)
    {
        printf("%d found at location %d\n", item, mid);
    }
    else
    {
        printf("Item not found\n");
    }
}
void recursiveBsearch(int *arr, int beg, int end, int item)
{
    int mid = (beg + end) / 2;
    if (beg == end && arr[mid] != item)
    {
        printf("Item not found\n");
        return;
    }
    if (arr[mid] == item)
    {
        printf("%d found at location %d\n", item, mid);
        return;
    }
    else if (arr[mid] > item)
    {
        recursiveBsearch(arr, beg, mid - 1, item);
    }
    else
    {
        recursiveBsearch(arr, mid + 1, end, item);
    }
}
int main()
{
    int size, *arr, i, ch, item;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    arr = (int *)malloc(sizeof(int) * size);
    printf("Enter the array elements one by one:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", (arr + i));
    }
    while (1)
    {
        printf("\n1 for itertaive linear search\n2 for iterative binary search\n3 for recursive linear search\n4 for recursive binary search\n5 for exit\nYour choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the item you want to find:");
            scanf("%d", &item);
            iterativeLSearch(arr, item, size);
            break;
        case 2:
            printf("\nEnter the item you want to find:");
            scanf("%d", &item);
            recursiveLSearch(arr, item, 0, size);
            break;
        case 3:
            printf("\nEnter the item you want to find:");
            scanf("%d", &item);
            iterativeBSearch(arr, 0, size - 1, item);
            break;
        case 4:
            printf("\nEnter the item you want to find:");
            scanf("%d", &item);
            recursiveBsearch(arr, 0, size - 1, item);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice!\n");
        }
    }
}