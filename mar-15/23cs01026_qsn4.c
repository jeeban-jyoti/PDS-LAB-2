#include <stdio.h>
#include <stdlib.h>

int moreThanOnce(int *arr, int n) {
    int ref = -1;
    for(int i = 1; i <= n; i++){
        int check = 0;
        for(int j = 0; j < n + 1; j++){

            if(arr[j] == i){
                check++;
            }
        }

        if(check == 0){
            printf("All the numbers between [1, n] does not exist int he array!\n");
            return -1;
        }
        else if(check == 1){
            check = 0;
            continue;
        }
        else if(check == 2){
            ref = i;
        }
        else{
            printf("All the numbers between [1, n] does not exist int he array!\n");
            return -1;
        }
        check = 0;
    }

    if(ref == -1){
        printf("None of the elements repeats in the array.");
    }

    return ref;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n+1) * sizeof(int));

    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n+1; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    for (int i = 0; i < n+1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int var = moreThanOnce(arr, n);

    if(var != -1){
        printf("Repeated element is: %d\n",var);
    }

    return 0;
}