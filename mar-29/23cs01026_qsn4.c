// We have to define a fixed size array with unions.it cannot be changed dynamically with runtime.

#include <stdio.h>
typedef union arrays
{
    int arr1[10];
    float arr2[10];
    char arr3[10];
} ar;

int main()
{
    ar ar1;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &ar1.arr1[i]);
    }
    printf("\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ar1.arr1[i]);
    }
    printf("\n\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &ar1.arr2[i]);
    }
    printf("\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%f ", ar1.arr2[i]);
    }
    printf("\n\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%c", &ar1.arr3[i]);
        getchar();
    }
    printf("\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", ar1.arr3[i]);
    }

    return 0;
}