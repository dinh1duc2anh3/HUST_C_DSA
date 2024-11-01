#include <stdio.h>
#include <stdlib.h>

int rows, columns;

int C(int k, int n, int *a1d) {
    if (a1d[(k - 1) * columns + (n - 1)] == 0) {
        if (k == 0 || k == n) {
            a1d[(k - 1) * columns + (n - 1)] = 1;
        } else {
            a1d[(k - 1) * columns + (n - 1)] = C(k - 1, n - 1, a1d) + C(k, n - 1, a1d);
        }
        return a1d[(k - 1) * columns + (n - 1)];
    } else
        return a1d[(k - 1) * columns + (n - 1)];
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    rows = a;
    columns = b;

    int *a1d = (int *)malloc(a * b * sizeof(int));

    // init
    for (int i = 0; i < a * b; i++) {
        a1d[i] = 0;
    }

    printf("%d", C(a, b, a1d));

    // free
    free(a1d);

    return 0;
}
