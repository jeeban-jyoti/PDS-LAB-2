#include <stdio.h>
typedef struct CourseRecord
{
    char firstname[15];
    char lastname[15];
    char department[10];
    char courcecode[10];
    int marks[3];
} cr;
float avg(cr st)
{
    float avgmarks = 0;
    for (int i = 0; i < 3; i++)
    {
        avgmarks += st.marks[i];
    }
    return (avgmarks / 3);
}
int func(cr st)
{
    float num = avg(st);
    if (num < 35)
    {
        return 0;
    }
    return 1;
}
int main()
{
    cr st;
    printf("Enter the first name : ");
    gets(st.firstname);
    printf("Enter the last name : ");
    gets(st.lastname);
    printf("Enter the Department : ");
    gets(st.department);
    printf("Enter the courcecode : ");
    gets(st.courcecode);
    printf("Enter the marks of 3 subjects : ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &st.marks[i]);
    }
    float avgmarks = avg(st);
    int ans = func(st);
    printf("Average marks : %.2f\n", avgmarks);
    if (ans == 1)
    {
        printf("Status : passed\n", ans);
    }
    else
        printf("Status : failed\n", ans);

    return 0;
}