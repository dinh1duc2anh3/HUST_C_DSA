#include <stdio.h>

void find_element_positions(int n, int x, int arr[]) {
    int first_occurrence = -1;
    int last_occurrence = -1;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            if (first_occurrence == -1) {
                first_occurrence = i;
            }
            last_occurrence = i;
        }
    }

    if (first_occurrence == -1) {
        printf("NO\n");
    } else if (first_occurrence == last_occurrence) {
        printf("%d %d\n", first_occurrence, last_occurrence);
    } else {
        printf("%d %d\n", first_occurrence, last_occurrence);
    }
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    find_element_positions(n, x, arr);

    return 0;
}
