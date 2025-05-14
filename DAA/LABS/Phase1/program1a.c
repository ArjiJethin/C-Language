#include <stdio.h>
void LSearch(int arr[], int size, int target, int index[])
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            index[count++] = i;
        }
    }
    if (count == 0)
    {
        printf("Element not found in array\n");
        return;
    }
    printf("Element %d found at indices: ", target);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", index[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 3, 6, 7, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int index[size];
    LSearch(arr, size, target, index);
    return 0;
}