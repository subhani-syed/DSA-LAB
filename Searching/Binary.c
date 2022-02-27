#include<stdio.h>

int binarySeacrh(int arr[],int key,int low,int high){
    if(low<=high){
        int mid = (low+high)/2;
        if(key==arr[mid]){
            printf("Element Found at index %d ",mid);
            return 0;
        }else if(key<arr[mid]){
            binarySeacrh(arr,key,low,mid);
        }else{
            binarySeacrh(arr,key,mid+1,high);
        }
    }else{
        printf("Element not found\n");
        return 0;
    }
    
}

int main(){
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in sorted order\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched:\n");
    int element;
    scanf("%d",&element);

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(element==arr[mid]){
            printf("Element found at index %d \n",mid);
            break;
        }else if(element<arr[mid]){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    if(low>high){
        printf("Element not found\n");
    }
    // Recursive Function
    binarySeacrh(arr,element,0,n-1);
    return 0;
}