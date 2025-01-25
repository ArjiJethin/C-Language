#include <stdio.h>

struct student
{
    char name[20];
    int age;
    float percentage;
};

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student s[n];
    struct student *p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = &s[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of the student: ");
        scanf("%s", p[i]->name);
        printf("Enter the age of the student: ");
        scanf("%d", &p[i]->age);
        printf("Enter the percentage of the student: ");
        scanf("%f", &p[i]->percentage);
    }
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s\n", p[i]->name);
        printf("Age: %d\n", p[i]->age);
        printf("Percentage: %.2f\n", p[i]->percentage);
        printf("\n");
    }
}