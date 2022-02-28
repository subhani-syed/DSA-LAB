#include<stdio.h>
int queue[4];
int visited[4] = {0,0,0,0};
int matrix[4][4]={
    {1,0,1,1},
    {1,1,1,1},
    {0,1,0,1},
    {1,0,1,1}
};
int rear=-1;
int front = -1;
int que_empty();
void enqueue(int);
int dequeue();
void bfs(int);

int main(){
    int start;
    scanf("%d",&start);
    bfs(start);
    return 0;
}
void bfs(int v){
    enqueue(v);
    visited[v] =1;
    printf("%d -> ",dequeue());
    for(int i=0;i<4;i++){
        if(visited[i]==0&&matrix[v][i]!=0){
            enqueue(i);
        }
    }
    for(int i=0;i<4;i++){
        if(visited[i]==0){
            bfs(i);
        }
    }
}
void enqueue(int a){
    if(rear==3){
    }else{
        if(front==-1){
            front =0;
            rear++;
            queue[rear] = a;
        }else{
            rear++;
            queue[rear] = a;
        }
    }
}
int dequeue(){
    if(front>rear||front==-1){
        // printf("Queue is Empty\n");
    }else{
        front++;
        return queue[front-1];
    }
}
int que_empty(){
    if(front>rear||front==-1){
        // printf("Queue is Empty\n");
        return 1;
    }else{
        return 0;
    }
}