#include <stdio.h>
struct Student
{
    int studentId;
    char name[50];
    char grade;
    float marks[5];
    float averageMarks;
};

void calculateAverage(struct Student *student)
{
    float totalMarks = 0.0;
    for (int i = 0; i < 5; i++)
    {
        totalMarks += student->marks[i];
    }
    student->averageMarks = totalMarks / 5;
}

void assignGrages(struct Student *student)
{
    if (student->averageMarks >= 90)
    {
        student->grade = 'A';
    }
    else if (student->averageMarks >= 80)
    {
        student->grade = 'B';
    }
    else if (student->averageMarks >= 70)
    {
        student->grade = 'C';
    }
    else if (student->averageMarks >= 60)
    {
        student->grade = 'D';
    }
    else
    {
        student->grade = 'F';
    }
}

int main()
{
    struct Student students[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter student %d details\n", i + 1);
        printf("Enter student id: ");
        scanf("%d", &students[i].studentId);
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        for (int j = 0; j < 5; j++)
        {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
        calculateAverage(&students[i]);
        assignGrages(&students[i]);
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Student ID: %d\n", students[i].studentId);
        printf("Student Name: %s\n", students[i].name);
        printf("Average Marks: %.2f\n", students[i].averageMarks);
        printf("Grade: %c\n", students[i].grade);
        printf("\n");
    }
    return 0;
}