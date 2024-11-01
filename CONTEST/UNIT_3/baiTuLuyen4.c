#include <stdio.h>

// Hàm tính trung vị của hai dãy đã được sắp xếp
double findMedianSortedArrays(int nums1[], int size1, int nums2[], int size2) {
    int totalSize = size1 + size2;
    int merged[totalSize];
    
    int i = 0, j = 0, k = 0;

    // Merge hai dãy đã được sắp xếp vào một dãy mới
    while (i < size1 && j < size2) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = nums1[i++];
    }

    while (j < size2) {
        merged[k++] = nums2[j++];
    }

    // Tính trung vị của dãy mới
    if (totalSize % 2 == 0) {
        // Trường hợp dãy có số phần tử chẵn
        return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
    } else {
        // Trường hợp dãy có số phần tử lẻ
        return merged[totalSize / 2];
    }
}

int main() {
    int size1, size2;

    // Nhập kích thước của hai dãy
    printf("Nhap kich thuoc cua day 1: ");
    scanf("%d", &size1);

    int nums1[size1];
    printf("Nhap cac phan tu cua day 1: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Nhap kich thuoc cua day 2: ");
    scanf("%d", &size2);

    int nums2[size2];
    printf("Nhap cac phan tu cua day 2: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &nums2[i]);
    }

    // Tìm trung vị và in kết quả
    double median = findMedianSortedArrays(nums1, size1, nums2, size2);
    printf("Trung vi cua hai day la: %.5f\n", median);

    return 0;
}
