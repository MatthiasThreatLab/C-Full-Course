#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    
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

    FILE* pFileWrite = fopen("output.txt", "w");

    if (pFileWrite == NULL)
    {
        printf("Could not open the file");
        return 1;
    }

    char text[] = "hey hey hey";

    fprintf(pFileWrite, "%s", text);

    fclose(pFileWrite);

    FILE* pFileRead = fopen("output.txt", "r");
    char buffer[1024] = {0};

    if (pFileRead == NULL)
    {
        printf("Could not open the file");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), pFileRead) != NULL)
    {
        printf("%s", buffer);
    }
    

    fclose(pFileRead);


    int number = 0;
    printf("Enter the number of grades you want to enter in: ");
    scanf("%d", &number);

    char* grades = malloc(number * sizeof(char));
    // char* grades = calloc(number, sizeof(char)); // --> same as malloc but sets all allocateds bytes to 0

    if(grades == NULL) { // avoids segmentation fault
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < number; i++)
    {
        printf("Enter grade #%d: ", i+1);
        scanf(" %c", &grades[i]);
    }

    printf("\n\nHere are all the grades you have entered:\n");

    for (int i = 0; i < number; i++)
    {
        printf("Grade #%d: %c\n", i+1, grades[i]);
    }
    
    free(grades);
    grades = NULL;

    int number = 0;
    printf("Enter the number of grades you want to enter in: ");
    scanf("%d", &number);

    char* grades = malloc(number * sizeof(char));

    if(grades == NULL) { // avoids segmentation fault
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < number; i++)
    {
        printf("Enter grade #%d: ", i+1);
        scanf(" %c", &grades[i]);
    }

    int additionalNumberOfGrades = 0;
    printf("Enter how many grades you would like to add: ");
    scanf(" %d", &additionalNumberOfGrades);

    char* temp = realloc(grades, (number + additionalNumberOfGrades) * sizeof(char));

    if(temp == NULL) {
        
        printf("Memory reallocation failed!\n");
        return 1;

    } else if (additionalNumberOfGrades > 0) {

        grades = temp;
        temp = NULL;

        for (int i = number; i < number + additionalNumberOfGrades; i++) {
            printf("Enter grade #%d: ", i+1);
            scanf(" %c", &grades[i]);
        }

        
    }

    printf("\n\nHere are all the grades you have entered:\n");

    for (int i = 0; i < number + additionalNumberOfGrades; i++) {
        printf("Grade #%d: %c\n", i+1, grades[i]);
    }
    
    free(grades);
    grades = NULL;

    

    return 0;
}