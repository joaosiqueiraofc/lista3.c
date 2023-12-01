#include <stdio.h>
#include <string.h>

int romanToDecimal(char roman) {
    switch (roman) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToDecimalNumber(char *roman) {
    int result = 0;
    int prevValue = 0;

    for (int i = strlen(roman) - 1; i >= 0; i--) {
        int value = romanToDecimal(roman[i]);

        if (value < prevValue) {
            result -= value;
        } else {
            result += value;
        }

        prevValue = value;
    }

    return result;
}

void decimalToBinary(int decimal) {
    if (decimal > 1) {
        decimalToBinary(decimal / 2);
    }

    printf("%d", decimal % 2);
}

int main() {
    char roman[13];
   
    scanf("%s", roman);

    int decimal = romanToDecimalNumber(roman);

    printf("%s na base 2: ", roman);
    decimalToBinary(decimal);
    printf("\n%s na base 10: %d\n", roman, decimal);
    printf("%s na base 16: %x\n", roman, decimal);

    return 0;
}