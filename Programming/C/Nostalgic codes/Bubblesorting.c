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

int main() {
    int n,i,j;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements\n");
    for(i=0;i < n;i++) {
        scanf("%d",&a[i]);
    }
    printf("Before Sorting: ");
    for(i=0;i < n;i++) {
        printf("%d ",a[i]);
    }
    printf("\nAfter Sorting: ");
    bubblesort(a,n);
    return 0;
}