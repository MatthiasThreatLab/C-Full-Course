#include <stdio.h>
#include <math.h>

int main() {

    double principal = 1000.0;
    float interestRate = 10.0;
    int numberYears = 2;
    int numberCompoundedPerYear = 1;

    double finalAmount = 0.0;

    printf("Enter the principal: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (%%): ");
    scanf("%f", &interestRate);

    printf("Enter the # of years: ");
    scanf("%d", &numberYears);

    printf("Enter the # of times compounded per year: ");
    scanf("%d", &numberCompoundedPerYear);

    finalAmount = principal * pow((1 + (interestRate/100.0) / numberCompoundedPerYear), numberCompoundedPerYear * numberYears);

    printf("After %d years, the total will be $%.2lf", numberYears, finalAmount);
    return 0;
}