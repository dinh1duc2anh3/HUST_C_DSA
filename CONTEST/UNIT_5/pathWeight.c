#include <stdio.h>
#define  N 100




int main(){
    int weightGraph[N][N];
    int n;//so dinh
    int m;//so canh
    int path[N];

    scanf("%d %d",&n,&m); 

    //init
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n ; j++){
            weightGraph[i][j] = -1;
        }
    }    

    int head,tail,value;
    for (int i = 0; i < m; i ++){

        scanf("%d %d %d",&head,&tail,&value);
        weightGraph[head-1][tail-1] = value;
        // printf("%d %d %d %d\n",head, tail, weightGraph[head][tail] , weightGraph[tail][head]);
    }

    int k;
    scanf("%d",&k);
    for (int i = 0; i < k ; i ++){
        scanf("%d", &path[i] );
    }

    int sum = 0;
    for (int i = 0; i < k-1; i ++){
        int weight = weightGraph[path[i]-1][path[i+1]-1];
        if (weight == -1) {
            printf("-1\n");
            return 1;
        }
        sum += weight;
    }
    printf("%d",sum);

    return 0;
}