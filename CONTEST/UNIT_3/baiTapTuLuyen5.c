#include <stdio.h>

// Hàm tìm kiếm phần tử x trong ma trận đã sắp xếp
int searchInMatrix(int matrix[][5], int rows, int cols, int x) {
    int row = 0, col = cols - 1; // Bắt đầu từ góc phải của ma trận

    while (row < rows && col >= 0) {
        if (matrix[row][col] == x) {
            // Phần tử được tìm thấy
            printf("Phan tu %d duoc tim thay tai hang %d, cot %d.\n", x, row + 1, col + 1);
            return 1; // Trả về 1 nếu tìm thấy
        } else if (matrix[row][col] > x) {
            // Nếu phần tử hiện tại lớn hơn x, di chuyển về cột trước
            col--;
        } else {
            // Nếu phần tử hiện tại nhỏ hơn x, di chuyển xuống dòng tiếp theo
            row++;
        }
    }

    // Nếu không tìm thấy
    printf("Phan tu %d khong tim thay trong ma tran.\n", x);
    return 0;
}

int main() {
    int matrix[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int x;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &x);

    // Gọi hàm tìm kiếm
    searchInMatrix(matrix, 5, 5, x);

    return 0;
}
