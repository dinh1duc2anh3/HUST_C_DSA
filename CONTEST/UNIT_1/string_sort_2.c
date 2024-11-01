#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareString(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);
    while (getchar() != '\n');

    char **a = (char **)malloc(n * sizeof(char *));
    
    for (int i = 0; i < n; i++) {
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        a[i] = (char*)malloc((len + 1) * sizeof(char));
        strcpy(a[i], buffer);
    }

    // Sắp xếp mảng chuỗi
    qsort(a, n, sizeof(char *), compareString);

    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
