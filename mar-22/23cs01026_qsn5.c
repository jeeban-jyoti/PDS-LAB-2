#include <stdio.h>
typedef struct CourseRecord
{
    char firstname[15];
    char lastname[15];
    char department[10];
    char courcecode[10];
    int marks[3];
} course;
float avg(course student)
{
    float avgmarks = 0;
    for (int i = 0; i < 3; i++)
    {
        avgmarks += student.marks[i];
    }
    return (avgmarks / 3);
}
int func(course student)
{
    float num = avg(student);
    if (num < 35)
    {
        return 0;
    }
    return 1;
}
int main()
{
    course student;
    printf("Enter the first name : ");
    gets(student.firstname);
    printf("Enter the last name : ");
    gets(student.lastname);
    printf("Enter the Department : ");
    gets(student.department);
    printf("Enter the courcecode : ");
    gets(student.courcecode);
    printf("Enter the marks of 3 subjects : ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &student.marks[i]);
    }
    float avgmarks = avg(student);
    int ans = func(student);
    printf("Average marks : %.2f\n", avgmarks);
    if (ans == 1)
    {
        printf("Status : passed\n");
    }
    else
        printf("Status : failed\n");

    return 0;
}