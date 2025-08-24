#include <stdio.h>

int main() {
     int i;
     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
     for (i=0; i<10; i++) {
          printf("Address of the element is: %p\n", &arr[i]);
          //Print value of every address
          printf("Value of the address is: %d\n", arr[i]);
     }
     return 0;
     
}