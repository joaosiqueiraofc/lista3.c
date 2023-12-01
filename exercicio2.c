#include <stdio.h>
#include <math.h>

int main() {
    int months;
    double monthlyDeposit, interestRate;

    
    
 
    scanf("%d", &months);

   
    scanf("%lf", &monthlyDeposit);

    
    scanf("%lf", &interestRate);

    
    double totalAmount = 0;

    for (int i = 1; i <= months; ++i) {
        totalAmount += monthlyDeposit;
        totalAmount *= (1 + interestRate);

        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, totalAmount);
    }

    return 0;
}