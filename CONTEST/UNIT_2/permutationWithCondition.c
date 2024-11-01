#include <stdio.h>

#define SIZE 100

int visited[SIZE];
int a[SIZE];
int cnt = 0;

void Init(int visited[],int n){
    for (int i = 0; i < n ; i++){
        visited[i] = 0;
    }
}

int check(int v,int k){
    if (visited[v] != 0) return 0;
    if ((v % k ==0) || (k % v == 0)) return 1;;
    return 0;
}

void printSolution(int n){
    for (int i = 1; i <= n ; i ++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void Try(int k,int n){
    for (int v = 1; v <= n; v++){
        if (check(v,k)){
            a[k] = v;
            visited[v] = 1;
            if (k == n) {
                cnt++;
                // printSolution(n);
            }
            else Try(k+1,n);
            visited[v] = 0;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    Init(visited,SIZE);
    Try(1,n);
    printf("%d",cnt);
    return 0;
}