/* 
    DATA STRUCTURE: binary heap

    CODE:   1) uses array
            2) no menu but friendly function names
            3) take note of 2 heapify functions
            4) deletion in binary heap always occurs from root
            5) uses macro 'size' to manage size of array
    
    FUNCTIONS CODED:
            1) swap                     4) root_delete
            2) insert                   5) heapify_delete
            3) heapify_insert           6) level_order_traverse

    EXAMPLE USED: 
        before deletion:            after deletion:         in array;
                  72                        63              0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 
              54      63                54      61          72  54  61  27  36  45  61  18
            27  36  45  61            27  36  45  18
          18
*/

#include <stdio.h>
#define nl printf("\n")
#define debug printf("here: ")
#define SIZE 50

int max(int a, int b){return (a>b)?a:b;}

void swap(int *a, int *b){int temp = *a;*a = *b;*b = temp;}

void heapify_insert(int heap[], int index){
    while(index){
        if(heap[index]> heap[(index-1)/2]){swap(&heap[index],&heap[(index-1)/2]);}
        index = (index - 1)/2; 
    }
}

void heapify_delete(int heap[], int index){
    int i = 0;
    while(i<=index){
        int bigger = max(heap[2*i+1],heap[2*i+2]);
        if(heap[i] > bigger){break;}
        if(heap[2*i+1] > heap[2*(i+1)]){
            swap(&heap[2*i+1],&heap[i]);
            i = 2*i+1;
        }
        else{
            swap(&heap[2*(i+1)],&heap[i]);
            i = 2*i+2;
        }
    }
}

void insert(int *index, int heap[], int x){heap[++*index] = x;heapify_insert(heap,*index);}

void level_order_traverse(int heap[], int index){int i;for(i = 0; i <= index; ++i){printf("%d ",heap[i]);}nl;}

void root_delete(int heap[], int *index){
    swap(&heap[0], &heap[*index]);
    --*index;
    heapify_delete(heap,*index);
}

int main(){
    int heap[SIZE];
    int index = -1;
    insert(&index,heap,45);
    insert(&index,heap,36);
    insert(&index,heap,54);
    insert(&index,heap,27);
    insert(&index,heap,63);
    insert(&index,heap,72);
    insert(&index,heap,61);
    insert(&index,heap,18);
    level_order_traverse(heap,index);
    root_delete(heap,&index);
    level_order_traverse(heap,index);

    return 0;
}