#include <stdio.h>

void decimal_to_binary(int n) {
        if (n < 0) printf("0");
        int binary[32];
        int i = 0;

        // Chuyển đổi sang hệ cơ số 2 và lưu vào mảng binary
        while (n > 0) {
            binary[i] = n % 2;
            n = n / 2;
            i++;
        }

        // In ra kết quả theo đảo ngược mảng
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binary[j]);
        }
    
}

int main() {
    int n;
    scanf("%d", &n);
    while (getchar() != '\n');
    decimal_to_binary(n);
    return 0;
}
