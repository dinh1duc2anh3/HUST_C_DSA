#include <stdio.h>
#include <stdlib.h>
//dynamic data structure

int main(){

    int *a , *sum, *prefixSum ;
    int n,k,m,h;
    scanf("%d",&n);

    a = (int*) malloc (n*sizeof(int));
    prefixSum = (int*) malloc ((n+1)*sizeof(int));

    prefixSum[0] = 0;
    for (int i = 0; i < n ; i++){
        scanf("%d", &a[i]);
        prefixSum[i+1] = prefixSum[i] + a[i] ;
    }

    scanf("%d",&k);
    
    sum = (int*) malloc (k*sizeof(int));
    for (int i = 0; i < k; i ++){
        scanf("%d %d",&m,&h);
        sum[i] = prefixSum[h] - prefixSum[m-1];
    }
    for (int i = 0; i< k; i++){
            printf("%d\n",sum[i]);
    }

    free(a);
    free(sum);
    free(prefixSum);

    return 0;
}