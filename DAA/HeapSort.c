#include <stdio.h>

// Function to heapify a subtree rooted at index i
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Left child larger than root?
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Right child larger than current largest?
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and heapify again
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

// Main Heap Sort function
void heapSort(int arr[], int n)
{
    // Step 1: Build max heap (start from last non-leaf node)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Step 2: One by one extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Swap current root with end element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        maxHeapify(arr, i, 0);
    }
}

// Helper function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array in ascending order:\n");
    printArray(arr, n);

    return 0;
}
