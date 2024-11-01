#include <stdio.h>
#include <string.h>
int numOfString[2];

#define SIZE 100


int main(){
    char str[SIZE];
    scanf("%s",str);


    numOfString[0] = 0;
    numOfString[1] = 0;

    numOfString[str[0] - '0'] ++;
    int i = 1;
    while (str[i] != '\0'){
        if (str[i] != str[i-1]) {
            numOfString[str[i] - '0']++;
        }
        i++;    
    }
    printf("%d %d",numOfString[0],numOfString[1]);
    return 0;
}

//problem 1: chữ số là một phần tử của str thì muốn chuyển nó sang số thì phải có : str[i] - '0'
//problem 2: khi day input qua dai thi bi loi