#include <stdio.h>
#include <string.h>

void daoNguocTu(char chuoi[]) {
    // Tạo mảng lưu trữ từ
    char tu[100][100];
    int i, j, k;

    // Xử lí phần từ xuống dòng
    int len = strlen(chuoi);
    while (len > 0 && chuoi[len - 1] == '\n'){
        chuoi[len - 1] = '\0';
    }
    
    // Đếm số từ trong chuỗi
    int soTu = 0;
    for (i = 0; chuoi[i] != '\0'; i++) {
        if (chuoi[i] == ' ' ) {
            tu[soTu][j] = '\0'; ;printf("%d",soTu);
            soTu++; 
            j = 0;
        } else {
            tu[soTu][j++] = chuoi[i];
        }
    }
    
    tu[soTu][j] = '\0'; // Kết thúc từ cuối cùng
    
    // In chuỗi đã đảo ngược thứ tự các từ
    for (k = soTu; k >= 0; k--) {
        
            printf("%s ", tu[k]);
        
    }
    printf("%s", tu);

}

int main() {
    char chuoi[1000];
    
    printf("Nhap chuoi can dao nguoc: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    daoNguocTu(chuoi);
    
    return 0;
}
