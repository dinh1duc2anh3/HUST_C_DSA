#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the maximum value in a given segment of the array


int main() {
    int n;
    scanf("%d", &n);

    int* sequence =(int*)malloc(n*sizeof(int));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
        sum += sequence[i];
    }

    char query[20];
    int start, end;

    // Process queries
    while (1) {
        scanf("%s", query);

        if (strcmp(query, "***") == 0) {
            break;
        }

        else if (strcmp(query, "find-max") == 0) {
            int max_val = sequence[0];
            for (int i = 1; i < n; i++) {
                if (sequence[i] > max_val) {
                    max_val = sequence[i];
                }
            }
            printf("%d\n", max_val);
        } 
        else if (strcmp(query, "find-min") == 0) {
            int min_val = sequence[0];
            for (int i = 1; i < n; i++) {
                if (sequence[i] < min_val) {
                    min_val = sequence[i];
                }
            }
            printf("%d\n", min_val);
        } else if (strcmp(query, "find-max-segment") == 0) {
            scanf("%d %d", &start, &end);
            printf("%d\n", findMaxSegment(sequence, start - 1, end - 1));
        } else if (strcmp(query, "sum") == 0) {
            printf("%d\n", sum);
        }
    }
    free(sequence);
    return 0;
}
