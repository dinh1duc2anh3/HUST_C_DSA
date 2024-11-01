#include <stdio.h>
/*tinh giai thua bang de quy se gay tran bo nho
khi n qua lon (stack overflow)*/
long long result = 1;
long long giaiThua (int n){
    if (n == 0 || n == 1) return 1;
    for (int i = 2; i <= n; i ++){
        result *= i;
    }
    return result;
}

 int main (){
    int n;
    scanf("%d",&n);
    printf("%lld",giaiThua(n));
    return 0;
 }