/* 
Problem ID : 42 

Problem : Trapping Rain Water

Statement : Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining..
*/

/* Problem Link
https://leetcode.com/problems/trapping-rain-water/description/
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1;
        int lMax=height[l], rMax=height[r];
        int total=0;
        while(l<r){
            if(lMax<rMax){
                l++;
                lMax=max(lMax, height[l]);
                total+=lMax-height[l];
            }
            else{
                r--;
                rMax=max(rMax, height[r]);
                total+=rMax-height[r];
            }
        }
        return total;
    }
};