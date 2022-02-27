#include<stdio.h>
int fact(int);
int main(){
    int n;
    scanf("%d",&n);
    printf("The factorial of %d is %d \n",n,fact(n));
}
int fact(int a){
    if(a==0){
        return 1;
    }else{
        return a*fact(a-1);
    }
}