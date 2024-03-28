#include <stdio.h>
typedef struct Class
{
    char roll_no[10];
    char name[30];
    char address[30];
    int age;
    float avg_marks;
} cl;
int main()
{
    cl class[6];
    for (int i = 0; i < 6; i++)
    {
        printf("Student no. : %d.\n", i + 1);
        printf("Enter roll no :");
        gets(class[i].roll_no);
        printf("Enter the name :");
        gets(class[i].name);
        printf("Enter the address :");
        gets(class[i].address);
        printf("Enter the age :");
        scanf("%d",&class[i].age);
        printf("Enter the average marks :");
        scanf("%f",&class[i].avg_marks);
    }
    for (int i = 0; i < 6; i++)
    {
        printf("Student no. : %d.\n", i + 1);
        printf("Roll no :");
        puts(class[i].roll_no);
        printf("Name :");
        puts(class[i].name);
        printf("Address :");
        puts(class[i].address);
        printf("Age :");
        printf("%d\n",class[i].age);
        printf("Average marks :");
        printf("%.2f\n",class[i].avg_marks);
    }

    return 0;
}