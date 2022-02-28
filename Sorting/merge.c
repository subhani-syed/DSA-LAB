#include<stdio.h>
int merge(int arr[],int l,int m,int h){
    int n1 = m-l+1;
    int n2 = h-m;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++){
        left[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        right[i] = arr[m+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k] = right[j];
        k++;
        j++;
    }
}
int mergeSort(int arr[],int l,int h){
    if(l<h){
        int m = (l+h)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);
        merge(arr,l,m,h);
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

    mergeSort(arr,0,n-1);
    printf("Elements after Sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}