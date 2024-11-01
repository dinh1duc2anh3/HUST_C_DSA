#include <stdio.h>
#include <stdlib.h>

int arrayEquality(int a[], int m, int b[] , int n){
    if (m != n) return 0;
    for ( int i = 0; i < m; i ++){
        if (a[i] != b[i] ) return 0;
    }
    return 1;
}

int main(){
    int size;
    scanf("%d",&size);
    int* arr = (int*)malloc(size*sizeof(int));

    int m,n;
    for (int i = 0; i< size; i ++){
        scanf("%d %d",&m,&n);
        int *a,*b;
        a = (int*)malloc(m*sizeof(int));
        b = (int*)malloc(n*sizeof(int));
        for (int j = 0; j < m ; j++){
            scanf("%d",&a[j]);
        }
        for (int k = 0; k < n ; k++){
            scanf("%d",&b[k]);
        }
        arr[i] = arrayEquality(a,m,b,n);
        free(a);
        free(b);
    }
    for (int i = 0; i < size; i ++){
        printf("%d\n",arr[i]);
    }
    free(arr);
    
    return 0;
}