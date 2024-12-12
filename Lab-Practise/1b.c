#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
bool verifyRegistration(char registration[])
{
    if (strlen(registration) != 10)
    {
        return false;
    }
    for (int i = 0; i < 2; i++)
    {
        if (!isalpha(registration[i]))
        {
            return false;
        }
    }
    for (int i = 2; i < 4; i++)
    {
        if (!isdigit(registration[i]))
        {
            return false;
        }
    }
    for (int i = 4; i < 6; i++)
    {
        if (!isalpha(registration[i]))
        {
            return false;
        }
    }
    for (int i = 6; i < 10; i++)
    {
        if (!isdigit(registration[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char registration[10];
    printf("Enter a 10-digit registration number: ");
    scanf("%s", registration);
    if (verifyRegistration(registration))
    {
        printf("Valid registration number\n");
    }
    else
    {
        printf("Invalid registration number\n");
    }
    return 0;
}