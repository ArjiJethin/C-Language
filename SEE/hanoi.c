#include <stdio.h>
void towerofhanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Disk 1 moved from %c to %c\n", from, to);
        return;
    }
    towerofhanoi(n - 1, from, aux, to);
    printf("Disk %d moved from %c to %c\n", n, from, to);
    towerofhanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerofhanoi(n, 'A', 'C', 'B');
    return 0;
}