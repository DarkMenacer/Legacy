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