#include <stdio.h>

int displayMenu() {
    int choice = 0;

    printf("------------------------------------\n");
    printf("Select an option: \n\n");
    printf("1. Check balance\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Exit\n\n");
    
    printf("Enter your choice: ");
    scanf(" %d", &choice);

    printf("\n\n");
    printf("------------------------------------\n");
    
    return choice;
}

void checkBalance(double balance) {
    printf("Your blance is $%.2lf\n\n", balance);
}

double depositMoney(double balance) {
    double amountDeposited;

    printf("How much would you like to deposit? ");
    scanf("%lf", &amountDeposited);

    balance += amountDeposited;

    printf("You successfully deposited $%.2lf. Your new balance is: $%.2lf\n\n", amountDeposited, balance);
    
    return balance;
}

double withdrawMoney(double balance) {
    double amountWithdrawn;
    
    printf("How much would you like to withdraw? ");
    scanf("%lf", &amountWithdrawn);

    if (amountWithdrawn <= balance) {
        balance -= amountWithdrawn;

        printf("You successfully withdrew $%.2lf. Your new balance is: $%.2lf\n\n", amountWithdrawn, balance);
    } else {
        printf("Insufficient funds! Your balance is: $%.2lf\n\n", balance);
    }
    
    
    return balance;
}

int main() {

    int menuChoice = 0;
    double balance = 1250.0;

    while(1==1) {
        
        menuChoice = displayMenu();

        if (menuChoice == 1) {

            checkBalance(balance);

        } else if ( menuChoice == 2) {

            balance = depositMoney(balance);

        } else if (menuChoice == 3) {

            balance = withdrawMoney(balance);

        } else if (menuChoice == 4) {
            
            break;

        }
        
        
        

    }
    
    return 0;
}