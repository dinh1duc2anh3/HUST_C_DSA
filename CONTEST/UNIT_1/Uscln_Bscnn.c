//1 = true ; 0 = false
//giai thuat euclid : ucln(a,b) = ucln(a mod b,b) (voi a >b )
// bcnn = a*b/ucln(a,b)

#include <stdio.h>
#include <math.h>
#define N 100

int v,n,a,b;
void nl(){
	printf("\n");
}

int equal(int a, int b){
	if (b == 0) return 1;
	return 0;
}

int ucln(int a, int b){
	if (equal(a,b)) return a;
	ucln(b, a%b);
}

int bcnn(int a, int b){
	return a*b/ucln(a,b);
}

int main(){
	scanf("%d %d",&a,&b);
	if (a == 0 && b == 0) {
		printf("0 0");
		return 1;
	}
	printf("%d %d",abs(ucln(a,b)),abs(bcnn(a,b)));
	
	return 0;
}



