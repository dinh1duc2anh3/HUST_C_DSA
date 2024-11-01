//1 = true ; 0 = false

#include <stdio.h>
#include <math.h>
#define N 100
int v,n,i;
void nl(){
	printf("\n");
}

int checksnt(int v){//v
	for (int i = 2; i <= sqrt(double (v)) ; i++) if ( (v % i) == 0) return 0;
	return 1;
}


int main(){
	scanf("%d",&n); //n
	for (int i = 2; i < n ; i++) if (checksnt(i)) printf("%d ",i); //i
	return 0;
}



