#include <stdio.h>
typedef struct address
{
    char street[10];
    char city[10];
    int zipcode;
} ad;

typedef struct person
{
    char name[30];
    ad address;
} prs;

int main()
{
    prs p1;
    printf("Enter the name :");
    gets(p1.name);
    printf("Enter the street :");
    gets(p1.address.street);
    printf("Enter the city :");
    gets(p1.address.city);
    printf("Enter the zipcode :");
    scanf("%d", &p1.address.zipcode);

    printf("Name :");
    puts(p1.name);
    printf("Street :");
    puts(p1.address.street);
    printf("City :");
    puts(p1.address.city);
    printf("Zipcode :%d", p1.address.zipcode);
    return 0;
}