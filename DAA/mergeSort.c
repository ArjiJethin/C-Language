#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (int itr = low; itr <= high; itr++)
    {
        arr[itr] = temp[itr - low];
    }

    free(temp);
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    if (n <= 0)
    {
        printf("Array size must be positive!\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter element number %d:", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
