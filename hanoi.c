#include<stdio.h>
void hanoi(int n,char src,char aux,char dest){
    if(n==1){
        printf("Move Disk %d from %c to %c \n",n,src,dest);
    }else{
        hanoi(n-1,src,dest,aux);
        printf("Move Disk %d from %c to %c \n",n,src,dest);
        hanoi(n-1,aux,src,dest);
    }
}
int main(){
    int n;
    char src,aux,des;
    scanf("%d %c %c %c",&n,&src,&aux,&des);
    
    hanoi(n,src,aux,des);
    return 0;
}
