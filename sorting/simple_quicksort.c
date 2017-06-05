#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void print(int size,int * ar){
    for(int i=0;i<size;i++){
        printf("%d ",ar[i]);
        
    }
    
    
}

void merge(int li,int * left,int ci,int * center,int ri,int *right,int * ar){
    int i=0;
    int j=0;
    //printf("Left \n");
    while(j<li){
        // printf("%d \n",left[j]);
        ar[i]=left[j];
        i++;
        j++;
    }
    j=0;
    //printf("center \n");
    while(j<ci){
        //printf("%d \n",center[j]);
        ar[i]=center[j];
        i++;
        j++;
    }
    j=0;
    //printf("right \n");
    while(j<ri){
        //printf("%d \n",right[j]);
        ar[i]=right[j];
        i++;
        j++;
    }
    
    
}

void partition(int ar_size, int *  ar) {
    int left[ar_size];
    left[0]=0;
    int li=0;
    int center[ar_size];
    center[0]=0;
    int ci=0;
    int right[ar_size];
    right[0]=0;
    int ri=0;
    
    for(int i=0;i<ar_size;i++){
        if(ar[i]>ar[0]){
            right[ri++]=ar[i];
        }
        else if(ar[i]<ar[0]){
            left[li++]=ar[i];
            
        }
        else{
            center[ci++]=ar[i];
        }
    }
    
    if(li>1){
        partition(li,left);
        
        merge(li,left,ci,center,ri,right,ar);
        
        partition(ri,right);
        merge(li,left,ci,center,ri,right,ar);
        printf("THis print \n");
        print(ar_size,ar);
        printf("\n");
        
        
    }
    else{
        if(ci>1){
            partition(ci,center);
            merge(li,left,ci,center,ri,right,ar);
            // printf("THis printn 1 \n");
            print(ar_size,ar);
            printf("\n");
        }
        else{
            if(ri>1){
                partition(ri,right);
                merge(li,left,ci,center,ri,right,ar);
                //printf("THis print 2 \n");
                print(ar_size,ar);
                printf("\n");
            }
            if(ri <=1 && ci<=1 && li<=1){
                if((ri==1 && li==1) || (ci==1 && li==1) || (ci==1 && ri==1)){
                    //we have completely partitoned left right and center
                    merge(li,left,ci,center,ri,right,ar);
                    //printf("THis print 3 \n");
                    print(ar_size,ar);
                    printf("\n");
                }
            }
        }
        
    }
    
    
    
    
    
}
int main(void) {
    
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        scanf("%d", &_ar[_ar_i]);
    }
    
    partition(_ar_size, _ar);
    
    return 0;
}
