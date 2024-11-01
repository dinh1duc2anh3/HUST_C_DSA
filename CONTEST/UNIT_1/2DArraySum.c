
#include <stdio.h>
#define N 100

int sum,m,n,i,j,a[N][N];
void nl(){
	printf("\n");
}

void arrayInput(){
	scanf("%d %d",&m,&n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n ; j++) scanf("%d",&a[i][j]);
	}
}

int arraySum(){
	sum = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++) sum = sum+a[i][j];
	}
	return sum;
}
int main(){
	arrayInput();
	printf("%d",arraySum());
	return 0;
}



