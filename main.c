#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    
    // this is a comment
    /*
    This is a 
    multiline comment
    */

    int age = 25;
    char grade = 'S';
    char name[] = "Matthias";
    float pi_float = 3.123456789123456789123456789;
    double pi_double = 3.123456789123456789123456789;
    bool isOld;

    printf("Hello world!\n");
    printf("My name is %s and I'm %d years old\n", name, age);
    printf("Last math test, I got an %c.\n", grade);
    printf("pi is %f, but to be more precise it is %.15lf\n", pi_float, pi_double);

    if (age > 70) {
        isOld = true;
    } else {
        isOld = false;
    }

    if (isOld) {
        printf("Damn I'm bloody old\n");
    }

    int num1 = 1;
    int num2 = 10;
    int num3 = 100;

    printf("%4d\n", num1);
    printf("%-4d\n", num2);
    printf("%04d\n", num3);

    float price1 = 19.99;
    float price2 = 1.50;
    float price3 = -100.00;
    
    printf("%.1f\n", price1);
    printf("%+7.3f\n", price2);
    printf("%+10.3f\n", price3);

    int yourAge = 0;
    char yourGrade = '\0';
    char yourName[30] = "";
    float yourPrice = 0.0f;

    printf("Enter your grade (A to F): ");
    scanf(" %c", &yourGrade);

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // clear iunput buffer
    printf("Enter your name (30 char max): ");
    fgets(yourName, sizeof(yourName), stdin); // need fgets to accept white spaces.
    yourName[strlen(yourName) - 1] = '\0'; // removes \n that fgets adds at the end

    printf("Enter your age: ");
    scanf("%d", &yourAge);

    printf("Enter your price: ");
    scanf("%f", &yourPrice);
    
    printf("Your age is: %d\n", yourAge);
    printf("Your grade is: %c\n", yourGrade);
    printf("Your name is: %s\n", yourName);
    printf("Your price is: %.2f\n", yourPrice);
    

    return 0;
}