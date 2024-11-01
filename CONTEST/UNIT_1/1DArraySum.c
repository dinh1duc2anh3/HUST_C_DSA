
#include <stdio.h>
#define N 100

int sum,n,i,a[N];
void nl(){
	printf("\n");
}

void arrayInput(){
	scanf("%d",&n);
	for (int i = 0; i < n ; i++) scanf("%d",&a[i]);
}

int arraySum(){
	sum = a[0];
	for (int i = 1; i <n ; i++) sum = sum + a[i];
	return sum;
}
int main(){
	arrayInput();
	printf("%d",arraySum());
	return 0;
}



