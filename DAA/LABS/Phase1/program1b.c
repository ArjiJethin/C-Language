#include <stdio.h>
int validate(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

int BinarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    if (validate(arr, size))
    {
        int index = BinarySearch(arr, size, key);
        if (index == -1)
        {
            printf("Element not found\n");
        }
        else
        {
            printf("Element found at index %d\n", index);
        }
    }
}
