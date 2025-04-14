#include<stdio.h>
#include<stdlib.h>

void buildHeap(int[], int);
void Heapify(int[], int, int);
void swap(int*, int*);
void print_bianaty_heap(int[], int);

void buildHeap(int arr[], int size)
{
    int i = size /2;
    for (; i >= 0; i--)
        Heapify(arr, i, size);
}

void Heapify(int arr[], int index, int size)
{
    int left = 2 * index + 1;
    int right = left + 1;

    int max = index;

    if(left <= size && arr[left] > arr[max])
        max = left;
    if(right <= size && arr[right] > arr[max])
        max = right;
    if(index != max)
    {
        swap(&arr[max], &arr[index]);
        Heapify(arr, max, size);
    }
}

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void print_bianary_heap(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("The Array Elements Are:\n");
    print_bianary_heap(arr, size);

    printf("Constructing Heap...\n");
    buildHeap(arr, size - 1);

    printf("The Array Element Are:\n");
    print_bianary_heap(arr, size);

    return 0;
}