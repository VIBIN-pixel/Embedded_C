#include<stdio.h>

int main() {
int i, sum=0;    
int mark[10] = {1,2,3,4,5,6,7,8,9,10};

for (i=0; i<10; i++) {
    sum = sum + mark[i];
}
printf("The sum of array: %d\n", sum);

//print odd numbers
printf("Odd numbers in the array are: ");
for (i=0; i<10; i++) {
    if(mark[i] % 2 !=0) {
        printf("%d ", mark[i]);
    }
}
return 0;
}