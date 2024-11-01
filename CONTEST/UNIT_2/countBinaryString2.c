#include <stdio.h>

int numOfString[2];

int main() {
    char c;
    int prevChar = -1; // -1 represents an uninitialized state
    while (scanf("%c", &c) != EOF && c != '\n') {
            if (prevChar == -1 || c != prevChar) {
                numOfString[c - '0']++;
            }
            prevChar = c;
        
    }
    printf("%d %d", numOfString[0], numOfString[1]);
    return 0;
}
