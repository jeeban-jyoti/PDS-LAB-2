#include <stdio.h>
#include <string.h>
#include <math.h>
#define max_students 100

typedef struct student
{
    char name[30];
    int roll_no;
    float pr;
} st;

st students[max_students];
int numstudents = 0;
void insert()
{
    if (numstudents < max_students)
    {
        printf("Enter your name: ");
        gets(students[numstudents].name);

        printf("Enter your roll number : ");
        scanf("%d", &students[numstudents].roll_no);

        printf("Enter your pr : ");
        scanf("%f", &students[numstudents].pr);
        numstudents++;
    }
    else
        printf("Student-list is Full.Cannot add more students.\n");
}
void viewstudent()
{
    if (numstudents > 0)
    {
        printf("\nStudentslist\n");
        printf("\n");
        printf("%-20s%-30s%-20s%-20s\n", "Sr no.", "Name", "Roll no.", "Percentage");
        printf("\n");
        for (int i = 0; i < numstudents; i++)
        {
            printf("%-18d: %-30s%-20d%-20.2f\n", i + 1, students[i].name, students[i].roll_no, students[i].pr);
        }
    }
    else
        printf("No students to display\n");
}
void sortname()
{
    int size = numstudents;
    {
        int issorted = 0;
        while (size != 1)
        {
            int val = 0;
            for (int i = 0; i < size - 1; i++)
            {
                issorted = 1;
                if (strcmp(students[i].name, students[i + 1].name) == 1)
                {
                    st temp = students[i];
                    students[i] = students[i + 1];
                    students[i + 1] = temp;
                    issorted = 0;
                }
            }
            if (issorted)
            {
                return;
            }
            size--;
        }
    }
    viewstudent();
}
void sortrollno()
{
    int size = numstudents;
    {
        int issorted = 0;
        while (size != 1)
        {
            for (int i = 0; i < size - 1; i++)
            {
                issorted = 1;
                if (students[i].roll_no > students[i + 1].roll_no)
                {
                    st temp = students[i];
                    students[i] = students[i + 1];
                    students[i + 1] = temp;
                    issorted = 0;
                }
            }
            if (issorted)
            {
                return;
            }
            size--;
        }
    }
}
char *findOne(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < numstudents; i++)
    {
        char *str2 = students[i].name;
        int flag = 0;
        for (int j = 0; j < len; j++)
        {
            if (str[i] == str2[i])
            {
                flag = 1;
            }
            else
                flag = 0;
        }
        if (flag == 1)
        {
            return students[i].name;
        }
    }
    return '\0';
}
void specs(float *arr)
{
    arr[0] = numstudents;
    float max = students[0].pr, min = students[0].pr, mean = 0, stdd = 0;
    for (int i = 0; i < numstudents; i++)
    {
        mean += students[i].pr;
        if (students[i].pr > max)
        {
            max = students[i].pr;
        }
        if (students[i].pr < min)
        {
            min = students[i].pr;
        }
    }
    mean /= numstudents;
    arr[1] = max;
    arr[2] = min;
    arr[3] = mean;
    for (int i = 0; i < numstudents; i++)
    {
        stdd += (students[i].pr - mean) * (students[i].pr - mean);
    }
    stdd /= numstudents;
    stdd = sqrt(stdd);
    arr[4] = stdd;
}
void delete(int num)
{
    int index = -1;
    for (int i = 0; i < numstudents; i++)
    {
        if (students[i].roll_no == num)
        {
            index = i;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < numstudents; i++)
        {
            students[i] = students[i + 1];
        }
        numstudents--;
    }
    else
        printf("Given roll no. does not exists\n");
}
int main()
{
    int choice;
    do
    {
        printf("\nStudent-list Menu\n");
        printf("0. Exit\n");
        printf("1. insert Student\n");
        printf("2. view Student\n");
        printf("3. sort Students by name\n");
        printf("4. Find one\n");
        printf("5. Specs\n");
        printf("6. Delete\n");
        printf("Enter your choice(pls enter the number): ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 0:
            printf("Exiting Application. Goodbye!\n");
            break;
        case 1:
            insert();
            sortrollno();
            break;
        case 2:
            viewstudent();
            break;

        case 3:
            sortname();
            break;
        case 4:
        {
            char str[30];
            printf("Enter the part of the name : ");
            gets(str);
            char *str2 = findOne(str);
            printf("The name which starts with the given part is : ");
            puts(str2);
            break;
        }
        case 5:
        {
            float arr[5];
            specs(arr);
            printf("Number of records in the database :%.0f\n", arr[0]);
            printf("Highest percentage :%.2f\n", arr[1]);
            printf("Lowest percentage :%.2f\n", arr[2]);
            printf("Mean :%.2f\n", arr[3]);
            printf("Standard deviation :%.2f\n", arr[4]);
            break;
        }
        case 6:
        {
            int num;
            printf("Enter the roll no. that you want to remove :");
            scanf("%d", &num);
            delete (num);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}