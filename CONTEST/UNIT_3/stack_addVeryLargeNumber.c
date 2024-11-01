#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void addLargeNumbers(char num1[], char num2[], char result[]) {
    int stack1[MAX_SIZE], stack2[MAX_SIZE], resultStack[MAX_SIZE];
    int top1 = -1, top2 = -1, resultTop = -1;
    int carry = 0;

    // Đưa các chữ số của số thứ nhất vào stack1
    for (int i = 0; i < strlen(num1); i++) {
        stack1[++top1] = num1[i] - '0';
    }

    // Đưa các chữ số của số thứ hai vào stack2
    for (int i = 0; i < strlen(num2); i++) {
        stack2[++top2] = num2[i] - '0';
    }

    // Thực hiện phép cộng từng chữ số
    while (top1 >= 0 || top2 >= 0 || carry) {
        int digitSum = carry;
        if (top1 >= 0) {
            digitSum += stack1[top1--];
        }
        if (top2 >= 0) {
            digitSum += stack2[top2--];
        }

        resultStack[++resultTop] = digitSum % 10;
        carry = digitSum / 10;
    }

    // Đưa kết quả từ stack vào chuỗi result
    while (resultTop >= 0) {
        result[++result[strlen(result)]] = resultStack[resultTop--] + '0';
    }
}

int main() {
    char num1[MAX_SIZE], num2[MAX_SIZE], result[MAX_SIZE];

    scanf("%s", num1);
    scanf("%s", num2);

    // Đặt kết quả là chuỗi rỗng
    result[0] = '\0';

    addLargeNumbers(num1, num2, result);

    printf("%s\n", result);

    return 0;
}
