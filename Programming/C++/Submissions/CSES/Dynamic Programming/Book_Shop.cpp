/*
Name:-              Book Shop
Platform:-          CSES
Date:-              8 September 2022
Type of Problem:-   0/1 Knapsack Problem
Complexity:-        O(n²)
Status:-            Solved

Solution in brief:
This is a classic 0/1 Knapsack Problem. Please refer to that before reading this explanation.
In the naive approach, for every book, we can either choose it or reject it, hence 2 possiblities.
So the solution goes O(2ⁿ) which is unacceptable. To optimise it, we use Dynamic Programming.
Let bᵢ represent iᵗʰ book and pr and pg represent price and pages.
Starting making the recursion tree with 0 books, it is realised that picking b₁ first and b₂ second
will evaluate to give same answer as picking picking b₂ first and b₁ second 
hence books are traversed in order (i.e. once a book is dropped it is never considered again).
For each node of the tree, the max of values of pages stored by its children is stored.
The tree bottoms out using the available budget, i.e. if no book can be bought further, the node is a leaf node.

This was the bottom-up approach. To implement this using top-down approach

Memoization table is constructed with budget (starting from 0 to total budget) as columns and specific book index as rows.
For each entry of the table, max pages that can be bought using that budget and those books (uptil that index) is stored.
So memoize[i][j] = max(memoize[i-1][j], pages[i] + memoize[i-1][j-price[i-1]]).
Here the first term represents the case where the new added book is not chosen and
the second term represents the case where it is chosen (additionally if there is any more books that can be bought using leftover).

Sample to understand solution:
Input:-
4 10
4 8 5 3
5 12 8 1

Output:-
13

Explanation:-
Most important part:- indexing of books

    Pages   1   5   8   12
    Index   1   2   3   4

Recursion Tree:-
                                                []empty
                [1]1                    [2]5               [3]8        [4]12
      [1,2]6      [1,3]9      [1,4]13  
[1,2,3] [1,2,4]   [1,3,4]

Memoization Table:-
    0  1  2  3  4  5  6  7  8  9  10 
0   0  0  0  0  0  0  0  0  0  0  0
1   0  0  0  1  1  1  1  1  1  1  1
2   0  0  0  1  5  5  5  6  6  6  6
3   0  0  0  1  5  8  8  8  9  13 13
4   0  0  0  1  5  8  8  8  12 13 13

*/
#include <vector>
#include <iostream>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define all(name) name.begin(),name.end()
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> price(n), pages(n), temp(x+1,0);
    take_loop_input_in(price,n);
    take_loop_input_in(pages,n);
    vector< vector<int> > memoize(n+1);
    for(int i=0;i<n+1;++i){memoize[i] = temp;}
    for(int i=0;i<n;++i){
        for(int j=0;j<x+1;++j){
            if(memoize[i][j] != 0){
                memoize[i+1][j] = memoize[i][j]; 
            }
            if(j>=price[i]){
                memoize[i+1][j] = max(memoize[i+1][j], pages[i] + memoize[i][j-price[i]]);
            }
        }
    }
    cout<<memoize[n][x];
    return 0;
}