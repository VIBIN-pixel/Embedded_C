#include <stdio.h>

void PrintBin(int n){
    int i, mask;
    for(i=31;i>=0;i--){
        mask = 1<<i;
        if(n & mask)
            printf("1");
        else
            printf("0");
    }
    printf("\n");

}
void SetBit(int n, int pos){
     int mask = 1<<pos;
     n = n | mask;
        
     PrintBin(n);
    
}

void ClearBit(int n, int pos){
     int mask = 1<<pos;
     n = n & (~mask);

     PrintBin(n);
}

int main() {
    int a,b;
    printf("Enter a number: ");
    scanf("%d", &a);
    PrintBin(a);
    
    printf("Enter the position to set the bit: ");
    scanf("%d", &b);
    SetBit(a,b);
    
    printf("Enter the number to clear the bit: ");
    scanf("%d", &b);
    ClearBit(a,b);
    return 0;
}