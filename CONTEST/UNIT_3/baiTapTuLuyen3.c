#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int n;
    printf("Nhap so luong day: ");
    scanf("%d", &n);

    int* arrays[n];
    int sizes[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap kich thuoc cua day %d: ", i + 1);
        scanf("%d", &sizes[i]);

        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));

        printf("Nhap cac phan tu cua day %d: ", i + 1);
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }

        // Sắp xếp dãy tăng dần
        for (int j = 0; j < sizes[i] - 1; j++) {
            for (int k = 0; k < sizes[i] - j - 1; k++) {
                if (arrays[i][k] > arrays[i][k + 1]) {
                    int temp = arrays[i][k];
                    arrays[i][k] = arrays[i][k + 1];
                    arrays[i][k + 1] = temp;
                }
            }
        }
    }

    // Kết hợp các dãy đã sắp xếp thành một dãy mới
    int resultSize = 0;
    for (int i = 0; i < n; i++) {
        resultSize += sizes[i];
    }

    int* result = (int*)malloc(resultSize * sizeof(int));

    int currentIndex = 0;
    for (int i = 0; i < n; i++) {
        merge(result, currentIndex, arrays[i], sizes[i], result);
        currentIndex += sizes[i];
    }

    // In dãy mới đã kết hợp và sắp xếp tăng dần
    printf("Day moi sau khi ket hop va sap xep tang dan: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        free(arrays[i]);
    }
    free(result);

    return 0;
}
