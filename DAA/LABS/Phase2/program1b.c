#include <stdio.h>
int BinarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return low;
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
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = BinarySearch(arr, n, key);
    (result == -1) ? printf("Element is not present in array") : printf("Element found at index %d", result);
    return 0;
}