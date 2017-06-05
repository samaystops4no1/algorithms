#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(int * arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
        
    }
    printf("\n");
}



int partition(int * arr,int initial,int final,int size){
    int pivot=arr[final];
    int i=initial-1,j;
    for(j=initial;j<final;j++){
        if(arr[j]<=pivot){
            i++;
            //swap(&arr[j],&arr[i]);
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    
    //swap(&arr[i+1],&arr[final]);
    int temp1=arr[i+1];
    arr[i+1]=arr[final];
    arr[final]=temp1;
    print(arr,size);
    return i+1;
    
}

void quickSort(int * arr,int initial,int final,int size){
    if(initial<final){
        int pIndex=partition(arr,initial,final,size);
        
        quickSort(arr,initial,pIndex-1,size);
        quickSort(arr,pIndex+1,final,size);
        
    }
    
}

int main() {
   
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        
    }
    quickSort(arr,0,size-1,size);
    
    return 0;
}
