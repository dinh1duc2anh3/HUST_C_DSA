#include <stdio.h>
#define N 1000000
//static data structure

int check(int a[],int j){
    if (a[j] >= 1 && a[j] <= 200) return 1;
    return 0;
}

int main(){
    int a[N],prefixSum[N+1],sum[N];
    int k,m,h,n;
    scanf("%d",&n);
    prefixSum[0] = 0;
    for (int i = 0; i < n ; i++){
        scanf("%d",&a[i]);
        if(!check(a,i)) return 1;
        prefixSum[i+1] = prefixSum[i] + a[i] ;
    }


    scanf("%d",&k);



    for (int i = 0; i < k; i ++){
        scanf("%d %d",&m,&h);
        if (m == 0) sum[i] = prefixSum[h];
        else {
            sum[i] = prefixSum[h] - prefixSum[m-1];
        }
        
    }
    for (int i = 0; i< k; i++){
            printf("%d\n",sum[i]);
    }
    return 0;
    }