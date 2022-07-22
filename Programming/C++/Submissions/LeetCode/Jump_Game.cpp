/*
Name:-              Jump Game
Platform:-          LeetCode
Date:-              23 March 2022
Type of Problem:-   Greedy, Back-Tracking
Complexity:-        O(n²)
Status:-            Solved

Solution in brief:
If nums[index+=nums[index]] != 0, then continue till the end of the array is reached (or passed)
Else at the point, where nums[index+=nums[index]] == 0 then 
    return to the parent_index and reduce it by one (effectively coming to index-1 in next iteration).
Backtracking is used to keep track of parent_indices.

Sample to understand solution:
Input:-
6
4 4 2 1 0 10

Output:-
1

Explanation:-
4 4 2 1 0 10
0 1 2 3 4 5

index: 0 (as nums[0 + 4] = 0 so index = parent_index)
index: 0 (nums[3] = 1))
index: 3 (as nums[3 + 1] = 0 so index = parent_index)
index: 0 
index: 0
index: 2
index: 2
index: 0
index: 0
index: 1

*/

#include <iostream>
#include <vector>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define what_is_here(name) cout<<#name<<": "<<name<<"\n"
using namespace std;
    
 bool back_track(vector<int> &nums, int parent_index, int *index){
    what_is_here(*index);
    if(*index + nums[*index] >= nums.size()-1){return true;}
    if(!nums[*index]){return false;}
    if(nums[*index + nums[*index]]){
        parent_index = *index;
        *index+=nums[*index];
        //cout<<"    ";
        return back_track(nums,parent_index,index);
    }
    else{
        --nums[*index];
        if(!nums[*index]){*index = parent_index;}
        //cout<<"    ";
        return back_track(nums,parent_index,index);
    }
}
    
bool canJump(vector<int>& nums) {
    int index = 0;
    if(nums.size()==1){return true;}
    return back_track(nums,0,&index);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    take_loop_input_in(nums,n);
    cout<<canJump(nums);
    return 0;
}