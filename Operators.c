#include<stdio.h>
int main() {

    int num1,num2,Add,Sub,Mul;
    float Div;

    printf("Enter the 2 numbers\n");
    scanf("%d%d", &num1, &num2);
    Add = num1+num2;
    Sub = num1-num2;
    Mul = num1*num2;
    Div =(float)num1/num2;

    printf("The add result is %d\n", Add);
    printf("The sub result is %d\n", Sub);
    printf("The mul result id %d\n", Mul);
    printf("The div result is %f\n", Div);

    return 0;
 }