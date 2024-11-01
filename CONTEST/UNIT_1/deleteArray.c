#include <stdio.h>

// Hàm tính số bước cần thiết để xoay vòng hoán vị A và B
int min_operations(int n, int perm_a[], int perm_b[]) {
    int pos_a1, pos_b1;

    // Tìm vị trí của số 1 trong hoán vị A
    for (int i = 0; i < n; ++i) {
        if (perm_a[i] == 1) {
            pos_a1 = i;
            break;
        }
    }

    // Tìm vị trí của số 1 trong hoán vị B
    for (int i = 0; i < n; ++i) {
        if (perm_b[i] == 1) {
            pos_b1 = i;
            break;
        }
    }

    // Đếm số bước cần thiết để xoay vòng hoán vị A và B để đưa số 1 về vị trí 1
    int steps_a = pos_a1;
    int steps_b = (pos_a1 <= pos_b1) ? pos_b1 : (n - pos_a1 + pos_b1);

    // Tổng số bước cần thiết
    int total_steps = steps_a + steps_b;

    return total_steps;
}

int main() {
    int n;
    scanf("%d", &n);

    int perm_a[n], perm_b[n];

    // Đọc hoán vị A từ input
    for (int i = 0; i < n; ++i) {
        scanf("%d", &perm_a[i]);
    }

    // Đọc hoán vị B từ input
    for (int i = 0; i < n; ++i) {
        scanf("%d", &perm_b[i]);
    }

    // Tính và in ra kết quả
    int result = min_operations(n, perm_a, perm_b);
    printf("%d\n", result);

    return 0;
}
