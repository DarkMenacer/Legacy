/* 
    DATA STRUCTURE: hash table (with linear probing)

    CODE:   1) uses array
            2) no menu but friendly function names
    
    FUNCTIONS CODED:
            1) hash_function    2) add_element

    NOTE:   1) hash function conatins multiple options to choose from (not all complete)
            2) macros used:- size, m, a (check code for description)
            3) doesn't include deletion of element

    EXAMPLE USED:
         hash table     elements
            0|          0
            1|          1
            2|          38 (37*1+ 1)
            3|          3
            4|          75 (37*2+ 1)
            ..
*/

#include <stdio.h>
#define SIZE 50     // Size of hash table
#define M 37        // number for hashing using division method
#define A 0.639     // number for hashing using multiplication method

int hash_function(int x){
    return x % M;       //METHOD 1: Division method
    /*return x*A;*/     //METHOD 2: Multiplication method
    /**/                //METHOD 3: Mid-Square method
    /**/                //METHOD 4: Folding method
}

void add_element(int x, int table[]){
    int pos = hash_function(x);
    int i=0;
    while(table[pos + i] != -1){++i;if(pos + i > SIZE){pos = 0;i=0;}}
    table[pos + i] = x;
}

int main(){
    int hash_table[SIZE],i;
    for(i=0;i<SIZE;++i){hash_table[i] = -1;}
    add_element(1,hash_table);
    add_element(38,hash_table);
    add_element(3,hash_table);
    add_element(75,hash_table);
    add_element(0,hash_table);
    for(i=0;i<SIZE;++i){printf("%d ", hash_table[i]);}
    return 0;
}