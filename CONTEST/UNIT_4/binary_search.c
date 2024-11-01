#include <stdio.h>

void searchMatrix(int matrix[][1000], int m, int n, int target, int *row, int *col) {
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int midValue = matrix[mid / n][mid % n];

        if (midValue == target) {
            *row = mid / n + 1;
            *col = mid % n + 1;
            return;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    *row = -1;
    *col = -1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[1000][1000];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int target;
    scanf("%d", &target);

    int row, col;
    searchMatrix(matrix, m, n, target, &row, &col);

    printf("%d %d\n", row, col);

    return 0;
}
