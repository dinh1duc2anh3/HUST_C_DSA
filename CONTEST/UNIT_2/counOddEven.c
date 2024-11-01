#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    int * a;
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    int countOdd =0, countEven = 0;
    for (int i= 0; i < n; i ++){
        scanf("%d",&a[i]);
        if (a[i] % 2 ==0 ) countEven++;
        else countOdd++;
    }
    printf("%d %d",countOdd,countEven);
    free(a);
    return 0;
}