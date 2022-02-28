#include<stdio.h>
int partiton(int arr[],int l,int h){
    int pi = arr[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<=pi){
            i = i+1;
            int  temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[h];
    arr[h] = temp;
    return i+1;
}
int quickSort(int arr[],int l,int h){
    if(l<h){
        int p = partiton(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}
int main(){
    int n;
    printf("Enter The number of Elements:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Elements before Sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    quickSort(arr,0,n-1);
    printf("Elements after Sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}