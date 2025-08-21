#include <stdio.h>
struct Book
{
     char title[50];
     char author[30];
     float price;
};

int main()
{ 
    struct Book books[3] = {
         {"Sapiens", "Yuval Noah Harari", 499.00},
         {"Thinking Fast and Slow", "Daniel Kahneman", 350.50},
         {"How to Win Friends", "Dale Carnegie", 299.00}
    }; 
    
    int i;
    int maxIndex = 0;
    
    //Display details
    printf("The book details is: \n");
    for (i=0; i<3; i++) {
        printf("\nBook %d\n", i+1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Price: %.2f\n", books[i].price);
        
        if (books[i].price > books[maxIndex].price) {
             maxIndex = i;
        }
   }
   printf("\nMost Expensive Book\n");
   printf("\nTitle: %s\n", books[maxIndex].title);
   printf("Author: %s\n", books[maxIndex].author);
   printf("Price: %.2f\n", books[maxIndex].price);
   
   return 0;
}