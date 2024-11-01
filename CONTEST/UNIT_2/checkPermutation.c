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

    int n;
    for (int k = 0; k< size; k ++){
        scanf("%d",&n);
        int * a = (int*)malloc(n*sizeof(int));
        int * visited = (int*)malloc((n+1)*sizeof(int)); /*problem : notice the size of 
        memory giving to the visited array*/
        
        //initial
        for (int i = 0; i< n; i ++){
            visited[i] = 0;
        }


        for (int i = 0; i < n; i ++){
            scanf("%d",&a[i]);
            visited[a[i]] ++;
        }
        
        for (int i = 1; i <= n ; i++){
            if (visited[i] == 0) {
                arr[k] = 0;
                break;
            }
            else {
                arr[k] = 1;
            }
        }
        free(a);
        free(visited);
    }
    for (int i = 0; i < size; i ++){
        printf("%d\n",arr[i]);
    }
    free(arr);
    
    return 0;
}