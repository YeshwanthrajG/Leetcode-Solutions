/* 
Problem ID : 3840 

Problem : House Robber V

Statement : You are a professional robber planning to rob houses along a street. Each house has a certain 
amount of money stashed and is protected by a security system with a color code.

You are given two integer arrays nums and colors, both of length n, where nums[i] is the amount of money 
in the ith house and colors[i] is the color code of that house.

You cannot rob two adjacent houses if they share the same color code.

Return the maximum amount of money you can rob.
*/

/* Problem Link
https://leetcode.com/problems/house-robber-v/description/
*/

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        if(n==1) return nums[0];
        long long p1=nums[0], p2=0;
        for(int i=1;i<n;i++){
            long long curr;
            if(colors[i]==colors[i-1]){
                curr=max(p1, (nums[i]+p2));
            }
            else{
                curr=p1+nums[i];
            }
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};