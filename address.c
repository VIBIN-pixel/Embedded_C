#include <stdio.h>

int val = 46;
int val1 = 28;
int val2 = 43;

int *ptr = &val;
int *ptr1 = &val1;
int *ptr2 = &val2;

int main()
{
    printf("Value of val= %d\n", val);
    printf("Value of val1= %d\n", val1);
    printf("Value of val2= %d\n", val2);
    printf("Address of val= %p\n", &val);
    printf("Address of val1= %p\n", &val1);
    printf("Address of val2= %p\n", &val2);
    printf("Content inside ptr = address of val= %p\n", ptr);
    printf("Content inside ptr1 = address of val= %p\n", ptr1);
    printf("Content inside ptr2 = address of val= %p\n", ptr2);
    printf("Value inside the address pointed by ptr= %d\n", *ptr);
    printf("Value inside the address pointed by ptr1= %d\n", *ptr1);
    printf("Value inside the address pointed by ptr2= %d\n", *ptr2);
    
    return 0;
}