#include <stdio.h>
typedef enum PayType
{
    HOURLY = 1,
    SALARY = 2
} pt;
typedef union EmpDetails
{
    float hourly_wage;
    double fixed;
    pt p2;
} ed;
typedef struct employee
{
    int employeeID;
    char name[50];
    ed emp1;
    pt p1;
} em;
int main()
{
    em e1;
    printf("Enter the employee id : ");
    scanf("%d", &e1.employeeID);
    getchar();
    printf("Enter employee name : ");
    gets(e1.name);
    printf("1.Hourly wage\n2.Fixed salary\n");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case HOURLY:
        e1.p1 = HOURLY;
        e1.emp1.p2 = HOURLY;
        printf("Enter hourly wage: ");
        scanf("%f", &e1.emp1.hourly_wage);
        break;
    case SALARY:
        e1.p1 = SALARY;
        e1.emp1.p2 = SALARY;
        printf("Enter fixed Salary: ");
        scanf("%lf", &e1.emp1.fixed);
        break;
    default:
        printf("Wrong choice\n");
        return 0;
    }
    if (e1.p1 == HOURLY)
    {
        printf("Employee ID: %d\n", e1.employeeID);
        printf("Employee name: %s\n", e1.name);
        printf("Employee hourly wage: %f", e1.emp1.hourly_wage);
    }
    if (e1.p1 == SALARY)
    {
        printf("Employee ID: %d\n", e1.employeeID);
        printf("Employee name: %s\n", e1.name);
        printf("Employee fixed salary: %lf", e1.emp1.fixed);
    }
    return 0;
}