#include <stdio.h>
#include <string.h>

int sortString(char* a,char* b){
    if (strcmp(a,b) < 0) {
        char* tmp = a;
        a=b;
        b=tmp;
    }
}



int main(){
    int n;
    scanf("%d",&n);
    while (getchar() != '\n');
    
    char **a = (char**)malloc(n * sizeof(char*));
    
    for (int i = 0; i < n; i++){
        a[i] = (char*)malloc(99*sizeof(char));
        scanf("%100s",a[i]);

    } 
    for (int i = 0; i < n; i ++){
        for (int j = n-1; j > 0; j --){
            compareString(a[j] , a[i]);
        }
    }
    
    for (int i = 0; i < n; i ++){
        free(a[i]);
    }
    free(a);
    return 0;
}