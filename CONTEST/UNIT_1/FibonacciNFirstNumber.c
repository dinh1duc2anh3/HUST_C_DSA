#include <stdio.h>
#define SIZE 100
int fibonaci[SIZE],n;
int fin(int n){
    fibonaci[n] = fibonaci[n-1] + fibonaci[n-2];
    return fibonaci[n];
}
int main(){
    scanf("%d",&n);
    printf("\n");
    if (n > 1) {
        fibonaci[1] = 0;
    fibonaci[2] = 1;

    printf("%d %d ",fibonaci[1],fibonaci[2]);

    for (int i = 3; i <= n; i++ ){
        printf("%d ",fin(i));
    }
    }
    else if (n == 1 || n == 0) {
        printf("0");
    }
    
    return 0;
}