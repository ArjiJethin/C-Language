#include <stdio.h>
int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the %d elements of the array: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("The elements in the array are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}