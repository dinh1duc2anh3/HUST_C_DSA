#include <stdio.h>
#include <math.h>

int main(){
    double x,y,result;
    scanf("%lf %lf",&x,&y);
    if (x <= y) {
        result = 5*x*sin(y) - 3 * pow(y,3.0)* x;
    }
    else {
         result =2 * pow (x,2.0) *y + 1 - x+y;

    }
    printf("%.4lf",result);
    return 0;
}