#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter The Element to be searched: ");
    scanf("%d",&key);
    int fib,fib1,fib2,offset,index;
    int count = 0;
    offset = -1;
    fib2 = 0;
    fib1 = 1;
    fib = fib1+fib2;
    while(fib<n){
        fib2 = fib1;
        fib1 = fib;
        fib = fib1+fib2;
    }
    while(fib>1){
        index = (fib2+offset<n-1)?fib2+offset:n-1;
        if(arr[index]<key){
            fib = fib1;
            fib1 = fib2;
            fib2 = fib-fib1;
            offset = index;
        }else if(arr[index]>key){
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }else if(arr[index]==key){
            printf("Element found at index %d \n",index);
            count++;
            break;
        }
    }
    if(count==0){
        printf("Element not found\n");
    }
    return 0;
}