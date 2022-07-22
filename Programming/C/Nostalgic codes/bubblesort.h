#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b=t;
}

void bubblesort(int x[],int n){         
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(x[j] > x[j+1]){
                swap(&x[j],&x[j+1]);
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d \n",x[i]);
    }
}