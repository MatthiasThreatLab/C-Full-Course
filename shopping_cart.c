#include <stdio.h>
#include <string.h>

int main() {

    printf("This is your shopping cart!\n\n");

    char item[50];
    float price;
    int quantity;
    
    printf("What item would you like to buy? ");
    fgets(item, sizeof(item), stdin); // need fgets to accept white spaces.
    item[strlen(item) - 1] = '\0'; // removes \n that fgets adds at the end

    printf("What is the price for each? ");
    scanf(" %f", &price);

    printf("How many would you like? ");
    scanf(" %d", &quantity);

    printf("\nYou have bought %d %s\n", quantity, item);
    printf("The total is: $%.2f", price*quantity);


    return 0;
}