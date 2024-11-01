#include <stdio.h>
#include <stdlib.h>
#define N 1000

//đệ quy có nhớ phiên bản nhớ bằng 2d array
int C(int k, int n, int a2d[N][N]){
    if ( a2d[k][n] == 0){
        if (k == 0 || k == n) {
            a2d[k][n] =  1;
        }

        else {
            a2d[k][n] = C(k-1,n-1,a2d) + C(k,n-1,a2d);
        }
        return a2d[k][n];
    }
    else return a2d[k][n];
    
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    int a2d[N][N];

    //init
    for (int i = 0; i < a; i++){
         for (int j = 0; j < b; j++ ){
            a2d[i][j] = 0;
         }
    }



    printf("%d",C(a,b,a2d));

    
    return 0;

}