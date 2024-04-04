#include <stdio.h>

union data
{
    int a;
    float b;
    char c;
};

int main()
{
    union data u1;

    // demonstration the way of using unions

    // you can assign value to only one variable at a time
    printf("Correct method\n");
    u1.a = 5;
    printf("%d\n", u1.a);
    u1.b = 5.55;
    printf("%f\n", u1.b);
    u1.c = 'a';
    printf("%c\n", u1.c);

    // demonstrating how not to use unions
    printf("\nIncorrect method\n");
    u1.a = 5;
    u1.b = 5.55;
    printf("%d\n", u1.a); // this will print a garbage value as we assigned value to variable b,so the data of a is lost

    return 0;
}