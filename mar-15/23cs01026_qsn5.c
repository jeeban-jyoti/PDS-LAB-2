#include <stdio.h>
void NinetyDegree(int n, int arr1[n][n], int a)
{
    for (int m = 0; m < a; m++){
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int k = *(*(arr1 + i) + j);
                *(*(arr1 + i) + j) = *(*(arr1 + j) + i);
                *(*(arr1 + j) + i) = k;
            }
        }
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < n; j++){
                int k = *(*(arr1 + i) + j);
                *(*(arr1 + i) + j) = *(*(arr1 + n - i - 1) + j);
                *(*(arr1 + n - i - 1) + j) = k;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr1[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            scanf("%d", *(arr1 + i) + j);
    }
    int a;
    scanf("%d", &a);
    NinetyDegree(n, arr1, a);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", *(*(arr1 + i) + j));
        printf("\n");
    }
    return 0;
}