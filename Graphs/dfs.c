#include<stdio.h>
int vertex = 4;
int visited[4]={0,0,0,0};
int matrix[4][4];
void dfs(int);
int main(){
    for(int i=0;i<4;i++){
        visited[i] = 0;
    }
    printf("Enter Matrix\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("Enter (%d,%d)\n",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    int start;
    printf("Enter the vertex to start from:\n");
    scanf("%d",&start);
    dfs(start);
    return 0;
}
void dfs(int a){
    printf("%d -> ",a);
    visited[a] = 1;
    for(int j=0;j<4;j++){
        if(!visited[j]&&matrix[a][j]==1){
            dfs(j);
        }
    }
}