#include<stdio.h>
int main() {
    printf("Size of int : %zu bytes\n", sizeof(int));
    printf("Size of float : %zu bytes\n", sizeof(float));
    printf("Size of double : %zu bytes\n", sizeof(double));
    printf("Size of char : %zu bytes\n", sizeof(char));

    int num;
    printf("Size of variable num : %zu bytes\n", sizeof(num));

    return 0;
}