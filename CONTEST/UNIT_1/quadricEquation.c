#include <stdio.h>
#include <math.h>
#define N 100
int a,b,c;
double delta;
void nl(){
	printf("\n");
}

void solution(){
	if (a == 0) printf(".4%lf",(double) -c/a);
	else {
		delta = b*b-4*a*c;
		if (delta < 0) printf("Phuong trinh da cho vo nghiem");
		else if (delta == 0) printf("Phuong trinh da cho co nghiem kep x=%.4lf",(float) (-b)/(2*a));
		else printf("Phuong trinh da cho co hai nghiem phan biet \nx1=%.4lf \nx2=%.4lf",(float)((-b+sqrt(delta))/(2*a)),(float)((-b-sqrt(delta))/(2*a)));
	}
}

int main(){
	scanf("%d %d %d",&a,&b,&c);	
	solution();
	return 0;
}


