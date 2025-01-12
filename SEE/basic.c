#include <stdio.h>
int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    return 0;
}