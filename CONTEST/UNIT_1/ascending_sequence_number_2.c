#include <stdio.h>
#include <stdlib.h>

void find_longest_ascending_sequence(double a[], int size) {
    int max_start_index = 0;
    int max_length = 0;
    int current_length = 1;
    int current_start_index = 0;

    for (int i = 1; i < size; i++) {
        if (a[i] > a[i - 1]) {
            current_length++;
        } else {
            if (max_length < current_length) {
                max_length = current_length;
                max_start_index = current_start_index;
            }
            current_length = 1;
            current_start_index = i;
        }
    }

    // Kiểm tra lần cuối nếu chuỗi tăng là chuỗi dài nhất ở cuối mảng
    if (max_length < current_length) {
        max_length = current_length;
        max_start_index = current_start_index;
    }

    for (int i = max_start_index; i < max_start_index + max_length; i++) {
        printf("%.2lf ", a[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }

    double* price;
    price = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        scanf("%lf", &price[i]);
    }
    find_longest_ascending_sequence(price, n);
    free(price);

    return 0;
}
