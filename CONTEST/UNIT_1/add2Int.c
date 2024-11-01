#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 100

void addLargeIntegers(const char *num1,const char *num2, char *result) {
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Make sure result has enough space
    int maxLength = len1 > len2 ? len1 + 1 : len2 + 1;

    int num1Array[MAX_DIGITS] = {0};
    int num2Array[MAX_DIGITS] = {0};
    int resultArray[MAX_DIGITS] = {0};

    // Convert num1 and num2 strings to integer arrays
    for (int i = 0; i < len1; ++i) {
        num1Array[i] = num1[len1 - i - 1] - '0';
    }

    for (int i = 0; i < len2; ++i) {
        num2Array[i] = num2[len2 - i - 1] - '0';
    }

    // Perform addition
    for (int i = 0; i < maxLength; ++i) {
        int sum = num1Array[i] + num2Array[i] + carry;
        resultArray[i] = sum % 10;
        carry = sum / 10;
    }

    // Convert resultArray to a string
    int resultLength = 0;
    for (int i = maxLength - 1; i >= 0; --i) {
        if (resultArray[i] != 0 || resultLength > 0) {
            result[resultLength++] = resultArray[i] + '0';
        }
    }

    result[resultLength] = '\0';

    // // Reverse the result string
    // for (int i = 0, j = resultLength - 1; i < j; ++i, --j) {
    //     char temp = result[i];
    //     result[i] = result[j];
    //     result[j] = temp;
    // }
}

int main() {
    char num1[MAX_DIGITS], num2[MAX_DIGITS];
    scanf("%s %s",num1,num2);

    // Allocate space for the result
    char result[MAX_DIGITS + 1];

    // Perform addition
    addLargeIntegers(num1, num2, result);

    // Print the result
    printf("%s\n", result);

    return 0;
}
