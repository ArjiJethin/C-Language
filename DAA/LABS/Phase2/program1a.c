#include <stdio.h>
void linearSearch(int arr[], int n, int key, int indices[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            indices[count++] = i;
        }
    }
    if (count == 0)
    {
        printf("Element not found in array\n");
        return;
    }
    printf("Element found at indices: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", indices[i]);
    }
}

int main()
{
    int arr[] = {10, 22, 8, 29, 30, 29, 41, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 29;
    int indices[n];
    linearSearch(arr, n, key, indices);
}