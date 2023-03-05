/*
Name:-              Chessboard and Queens
Platform:-          CSES
Date:-              3 September 2021
Type of Problem:-   Complete Search (Back-tracking)
Complexity:-        O(n!)
Status:-            Solved

Solution in brief:
For every queen placed, its corresponding row, column and primary & secondary diagonals become invalid.
Therefore 3 arrays 'column','prdiag','sediag' are created to monitor each of them.
It is ensured that only 1 queen can be placed on each row by iterating row-wise.
A simple back-tracking algorithm is contrived there-after.
Row 'i' is used as a means to progress ahead
'i' is only incremented if a queen is either already placed or IS placed during the iteration, else no solution is possible.   
For each row 'i':-  column 'j' , prdiag[j-i+7], sediag[i+j] or board[i][j] are checked to be true.
If true, queen cannot be placed on [i][j] and j is incremented. If j reaches 8 and still no queen is placed, the algorithm backtracks, i.e. i is decremented.
If false, queen is placed on [i][j], column 'j' , prdiag[j-i+7], sediag[i+j] are set true and 'i' is incremented to next state.
Now, if i reaches 8, that means 8 queens (0 to 7) are successfully placed on the board, therefore it is a possible solution.
Hence 'answer' is incremented, and the algorithm back-tracks.


Sample to understand solution:
Input:-
*.......
......*.
....*...
.......*
.*......
...*....
........
........

Output:-
50
*/

#include <iostream>
using namespace std;

void backtrack(int i, char board[8][8], int column[8], int prdiag[14], int sediag[14], int *answer){
    if(i==8){*answer+=1;return;}
    for(int j=0;j<8;j++){
        if(column[j] || prdiag[j-i+7] || sediag[i+j] || board[i][j]=='*'){continue;}
        column[j]=1;prdiag[j-i+7]=1;sediag[i+j]=1;
        backtrack(i+1,board,column,prdiag,sediag,answer);
        column[j] = 0; prdiag[j-i+7] = 0; sediag[i+j] = 0;
    }
}

int main(){
    char board[8][8];
    int column[8],prdiag[15],sediag[15];
    for(int i=0;i<8;++i){column[i]=0;prdiag[i]=0;sediag[i]=0;}
    for(int i=8;i<15;++i){prdiag[i]=0;sediag[i]=0;}
    for(int i = 0;i<8;++i){
        for(int j = 0;j<8;++j){cin>>board[i][j];}
    }
    int answer = 0;
    backtrack(0,board,column,prdiag,sediag,&answer);
    cout<<answer;
    return 0;
}