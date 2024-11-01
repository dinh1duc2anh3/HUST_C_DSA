#include <stdio.h>



int main(){
    char s[30];
    scanf("%30s",s);
    for (int i = 0; i <= 29; i ++){
        char c = s[i];
        if (c >= 97 && c <= 122) s[i] = s[i] -32;
        if (c >= 65 && c <= 90) s[i] = s[i] + 32;
        
    }
    printf("%s",s);
    
    return 0;
}