#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elemnts\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elemtns\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched:\n");
    int element;
    scanf("%d",&element);
    int flag = -1;
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            flag =i;
            break;
        }
    }
    if(flag==-1){
        printf("Element not found\n");
    }else{
        printf("Elemnt found at index %d \n",flag);
    }
    return 0;
}