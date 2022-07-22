/*
Name:-              Container with most water
Platform:-          LeetCode
Date:-              20 February 2022
Type of Problem:-   Greedy
Complexity:-        O(n)
Status:-            Solved

Solution in brief:

Sample to understand solution:
Input:-

Output:-

Explanation:-

*/

#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_area = 0;
        while(i<j){
            max_area = max(max_area,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j]){++i;}
            else{--j;}
        }      
        return max_area;
    }
};