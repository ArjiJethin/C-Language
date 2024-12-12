#include <stdio.h>
struct Student
{
    int studentID;
    char name[50];
    char grade;
    float marks[5];
    float averageMarks;
};

void calculateAverage(struct Student *student)
{
    float sum = 0.0;
    for (int i = 0; i < 5; i++)
    {
        sum += student->marks[i];
    }
    student->averageMarks = sum / 5;
}

void assignGrades(struct Student *student)
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
    struct Student *studentPtr = students;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter student ID: ");
        scanf("%d", &studentPtr->studentID);
        printf("Enter Name: ");
        scanf("%s", studentPtr->name);
        printf("Enter Marks for all 5 Subjects:- \n");
        for (int j = 0; j < 5; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("$d", &studentPtr->marks[j]);
        }
        calculateAverage(studentPtr);
        assignGrades(studentPtr);
        studentPtr++;
    }

    studentPtr = students;
    printf("\nStudent Details:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Student ID: %d\n", studentPtr->studentID);
        printf("Student Name: %s\n", studentPtr->name);
        printf("Average Marks: %.2f\n", studentPtr->averageMarks);
        printf("Grade: %c\n", studentPtr->grade);
        studentPtr++;
    }
}