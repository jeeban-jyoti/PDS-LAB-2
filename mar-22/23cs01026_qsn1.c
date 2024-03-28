#include <stdio.h>
#define MAX_NO_OF_COMPANIES 10
#define MAX_STRING_LENGTH 100

struct company{
    char name[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
    int noOfEmployee;
};
typedef struct company Company;

int main(){
    Company companies[MAX_NO_OF_COMPANIES];

    int T;
    printf("Enter the number of company names you want to enter (must be less than 10): ");
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        printf("Company No: %d\n", (i+1));

        fgets(companies[i].name, MAX_STRING_LENGTH, stdin);

        printf("Enter the name of company: ");
        fgets(companies[i].name, MAX_STRING_LENGTH, stdin);

        printf("Enter the address of company: ");
        fgets(companies[i].address, MAX_STRING_LENGTH, stdin);

        printf("Enter the phone number of company: ");
        fgets(companies[i].phone, MAX_STRING_LENGTH, stdin);

        printf("Enter the number of employees in the company: ");
        scanf("%d", &(companies[i].noOfEmployee));
        
    }
    
    printf("\n\n");

    for(int i = 0; i < T; i++){
        printf("Company number: %d\n", (i+1));
        printf("name -> %s", companies[i].name);
        printf("address -> %s", companies[i].address);
        printf("phone no. -> %s", companies[i].phone);
        printf("npo of employees -> %d\n\n\n", companies[i].noOfEmployee);
    }

    return 0;
}