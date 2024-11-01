
//nghien cuu khoa hoc\0

#include <stdio.h>
#include <string.h>

#define N 100


int main(){
    char string[N] , result[N];

    fgets(string,sizeof(string),stdin);
    

    int len = strlen(string);
    while (len > 0 && string[len - 1] == '\n'){
        string[len -1] = '\0';
    }

    int i = len -1;
    int j = len -1;
    while (i >= 0){
        
        if (string[i] == ' ') {
            for (int k = i+1; k <= j; k++){
                printf("%c",string[k]);
            }
            printf(" ");
            j = i-1;
        
        }
        i--;
    }
    i = 0;
    while (string[i] != ' '){
        printf("%c",string[i]);
        i++;
    }
    printf(" ");
    return 0;
}