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

    // Input integers into arr1
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &ar1.arr1[i]);
    }

    // Print integers from arr1
    printf("\nIntegers entered:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ar1.arr1[i]);
    }

    // Input floats into arr2
    printf("\n\nEnter 10 floats:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &ar1.arr2[i]);
    }

    // Print floats from arr2
    printf("\nFloats entered:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%f ", ar1.arr2[i]);
    }

    // Input characters into arr3
    printf("\n\nEnter 10 characters:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf(" %c", &ar1.arr3[i]); // Notice the space before %c to consume whitespace characters
        getchar(); // Clear newline characters from input buffer
    }

    // Print characters from arr3
    printf("\nCharacters entered:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", ar1.arr3[i]);
    }

    return 0;
}