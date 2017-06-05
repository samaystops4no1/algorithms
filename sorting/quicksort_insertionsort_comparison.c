#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void swap(int * a, int * b){
    int t=*a;
    *a=*b;
    *b=t;
    
}

void print(int * arr,int size){
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
}

int putInPlace(int key,int * arr,int swaps){
    
    for(int i=key;i>0;i--){
        if(arr[i]<=arr[i-1]){
            swaps++;
            swap(&arr[i],&arr[i-1]);
        }
        else{
            break;
        }
    }
    
    return swaps;
    
}

int insertionSort(int key,int size,int * arr,int swaps){
    swaps=putInPlace(key,arr,swaps);
    
    if(key<size-1){
        swaps=insertionSort(key+1,size,arr,swaps);
        return swaps;
    }
    else{
        return swaps;
    }
}

int partition(int * arr, int low, int high,int * swaps){
    
    int pivot=arr[high];
    int i=low-1;
    
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            *swaps=*swaps+1;
           
            swap(&arr[i],&arr[j]);
        }
    }
    *swaps=*swaps+1;
    //printf(" Wut %d",*swaps);
    swap(&arr[i+1],&arr[high]);
    
    return i+1;
}

int quickSort(int * arr, int low,int high,int swaps){
    if(low<high){
        int pIndex=partition(arr,low,high,&swaps);
        
        quickSort(arr,low,pIndex-1,swaps);
        quickSort(arr,pIndex+1,high,swaps);
        
        return swaps;
        
    }
    else{
        return swaps;
    }
}


void sorting(int * arr,int size){
    
   int insertionSwap=insertionSort(1,size,arr,0);
   //int quickSwap= quickSwap=quickSort(arr,0,size-1,0);
    
    
   //printf("\n %d",insertionSwap);
    //printf("\n %d",quickSwap);
    //printf("%d",quickSwap-insertionSwap);
}



int main() {
    clock_t t;
    t=clock();
    
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        
        scanf("%d",&arr[i]);
        
    }
    printf("Sorting the entered numbers...\n");
    t=clock();
    sorting(arr,size);
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("\nSorting took %f seconds to execute",time_taken);
    print(arr,size);
    printf("\n");
    return 0;
}
