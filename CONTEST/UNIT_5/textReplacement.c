#include <stdio.h>
#include <string.h>

int main() {
    char P1[1001], P2[1001], T[10001];

    // Đọc dữ liệu đầu vào
    fgets(P1, sizeof(P1), stdin);
    fgets(P2, sizeof(P2), stdin);
    fgets(T, sizeof(T), stdin);

    // Loại bỏ ký tự xuống dòng ở cuối mỗi xâu
    P1[strcspn(P1, "\n")] = '\0';
    P2[strcspn(P2, "\n")] = '\0';
    T[strcspn(T, "\n")] = '\0';

    // Thực hiện thay thế
    char *pos = T;
    while ((pos = strstr(pos, P1)) != NULL) {
        memmove(pos + strlen(P2), pos + strlen(P1), strlen(pos + strlen(P1)) + 1);
        memcpy(pos, P2, strlen(P2));
        pos += strlen(P2);
    }


    /*Sử dụng vòng lặp while để tìm và thay thế xâu P1 trong văn bản T.
        Hàm strstr được sử dụng để tìm vị trí xuất hiện đầu tiên của xâu P1 trong văn bản T.
        Nếu tìm thấy, memmove được sử dụng để di chuyển các ký tự sau vị trí tìm thấy để tạo khoảng trống cho xâu P2 mới.
        Sau đó, memcpy được sử dụng để sao chép xâu P2 vào vị trí tìm thấy.
        Con trỏ pos sau đó được di chuyển đến cuối xâu P2 mới thêm vào, để tiếp tục tìm kiếm và thay thế cho đến khi không còn xâu P1 nào nữa.*/

    // In kết quả
    printf("%s\n", T);

    return 0;
}
