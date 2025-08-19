#include<stdio.h>
int Add(int num1, int num2) {
    return num1+num2;
}
int Sub(int num1, int num2) {
    return num1-num2;
}
int Mul(int num1, int num2) {
    return num1*num2;
}
float Divetion(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Return 0 or handle error as needed
    }
    return (float)num1/(float)num1;
}
int main() {

    int num1,num2;
    int choice;
 
    printf("Enter the 1st numbers\n");
    scanf("%d", &num1);
    printf("Enter the 2nd numbers\n");
    scanf("%d", &num2);
    
    printf("Choose an operation:\n");

    printf("1. sum\n");
    printf("2. sub\n");
    printf("3. mul\n");
    printf("4. divetion\n");
    printf("Enter your choice (1-4): ");
     scanf("%d", &choice);
    if (choice == 1) {
        printf("Result: %d\n", Add(num1, num2));
    } else if (choice == 2) {
        printf("Result: %d\n", Sub(num1, num2));
    } else if (choice == 3) {
        printf("Result: %d\n", Mul(num1, num2));
    } else if (choice == 4) {
        printf("Result: %f13\n", Divetion(num1, num2));
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}