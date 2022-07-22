/*
Name:-              Grid Paths
Platform:-          CSES
Date:-              20 Oct 2021
Type of Problem:-   Complete Search (Back-Tracking, Pruning the search)
Complexity:-        ????
Status:-            Time Limit Error

Solution in brief:

*/

#include <iostream>
#include <string> 
using namespace std;

void movement(int *x, int *y, bool grid[7][7], char c, bool *red_flag, int init_x, int init_y){
    if(c=='U'){*x-=1;}
    else if(c=='D'){*x+=1;}
    else if(c=='R'){*y+=1;}
    else if(c=='L'){*y-=1;}
    if(grid[*x][*y] == 1 || *x<0 || *y<0 || *x>6 || *y>6 ){*red_flag = 1;*x=init_x;*y=init_y;}
    else{grid[*x][*y] = 1;}
}

bool invalid_state(int x, int y, bool grid[7][7]){
    if(x<0 || y<0 || x>6 || y>6 || (x==6 && y ==0)){return true;}
    if(y>0 && y<6){if((x==0 || x==6) && (grid[x][y-1]==0 && grid[x][y+1]==0)){return true;}}
    if(x>0 && x<6){if((y==0 || y==6) && (grid[x-1][y]==0 && grid[x+1][y]==0)){return true;}}
    if(x>1 && y >1){
        if(grid[x+1][y]==1 && grid[x-1][y] ==1){if(grid[x][y-1]!=1 && grid[x][y+1]!=1){return true;}}
        if(grid[x][y+1]==1 && grid[x][y-1] ==1){if(grid[x-1][y]!=1 && grid[x+1][y]!=1){return true;}}
    }
    if(grid[5][1]==1 && grid[5][0]!=1 && grid[6][1]!=1){return true;}
    if(grid[6][0]==1){return true;}
    return false;
}

void backtrack(int count, int *x, int *y, bool grid[7][7],string input,int *answer, bool *red_flag){
    if(count == 48 && *x == 6 &&  *y == 0){*answer = *answer+1;return;}
    int init_x = *x, init_y = *y;
    if(invalid_state(*x,*y,grid)){return;}

    if(input[count]!= '?'){
        movement(x,y,grid,input[count],red_flag,init_x,init_y);
        if(*red_flag != 1){backtrack(count+1,x,y,grid,input,answer,red_flag);}
        grid[*x][*y] = 0;
        *x = init_x; *y = init_y;
    }
    else{
        movement(x,y,grid,'U',red_flag,init_x,init_y);
        if(*red_flag != 1){backtrack(count+1,x,y,grid,input,answer,red_flag);grid[*x][*y] = 0;}
        *red_flag = 0; *x = init_x; *y = init_y;

        movement(x,y,grid,'D',red_flag,init_x,init_y);
        if(*red_flag != 1){backtrack(count+1,x,y,grid,input,answer,red_flag);grid[*x][*y] = 0;}
        *red_flag = 0; *x = init_x; *y = init_y;

        movement(x,y,grid,'R',red_flag,init_x,init_y);
        if(*red_flag != 1){backtrack(count+1,x,y,grid,input,answer,red_flag);grid[*x][*y] = 0;}
        *red_flag = 0; *x = init_x; *y = init_y; 

        movement(x,y,grid,'L',red_flag,init_x,init_y);
        if(*red_flag != 1){backtrack(count+1,x,y,grid,input,answer,red_flag);grid[*x][*y] = 0;}
        *red_flag = 0; *x = init_x; *y = init_y;
    }
}

int main(){
    bool grid[7][7], red_flag = 0;
    for(int i=0;i<7;++i){for(int j=0;j<7;++j){grid[i][j] = 0;}}
    grid[0][0]=1;
    string input;
    getline(cin,input);
    if(input[48]=='U'||input[48]=='R' || input[47] == 'U' || input[47]=='R'){cout<<0;exit(0);}
    int x=0,y=0,answer=0;
    backtrack(0,&x,&y,grid,input,&answer, &red_flag);
    cout<<answer;
    return 0;
}