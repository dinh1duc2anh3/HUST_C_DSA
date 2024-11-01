//1 = true ; 0 = false

#include <stdio.h>
#include <math.h>
#define N 100

int v,n,i,j,a[N];
void nl(){
	printf("\n");
}

int fibonaci(int n){
	
	printf("a[0] = ? \na[1] = ?\n");
	scanf("%d %d",&a[0],&a[1]);
	for (int i = 2 ; i <= n; i++){
		a[i] = a[i-2] + a[i-1];
	}
	return a[n];
}

int main(){
	scanf("%d",&n);
	
	printf("phan tu thu %d cua day fibonaci = %d",n,fibonaci(n-1));
	
	return 0;
}



