#include <stdio.h>
typedef struct Structure
{
    int a;
    int b;
    char c;
} Structure;
typedef union uni
{
    int d, e;
    char f;
} uni;
int main()
{
    Structure s1;
    uni u1;
    printf("Size of Structure is : %d\n", sizeof(s1));
    // The sizeof for a struct is not always equal to the sum of sizeof of each individual member. This is because of the padding added by the compiler to avoid alignment issues.
    printf("Size of Union is : %d\n", sizeof(u1));

    // memery allocation is defferent in union and structures, structure allocates memory more than or equal to the sum of individual memories of each memers of structures,
    return 0;
}