#include <stdio.h>

void Circular_Shift(int *p, int *q, int *r)
{
    int a = *q;
    *q = *p;
    *p = *r;
    *r = a;
}

int main(){
    int x, y, z;
    printf("Enter the value of x, y, z: ");
    scanf("%d%d%d", &x, &y, &z);

    printf("Value of x = %d, y = %d and z = %d\n", x, y, z);

    Circular_Shift(&x, &y, &z);

    printf("Value of x = %d, y = %d and z = %d\n", x, y, z);

    return 0;
}