/* 
Problem ID : 3736 

Problem : Minimum Moves to Equal Array Elements III

Statement : You are given an integer array nums.

In one move, you may increase the value of any single element nums[i] by 1.

Return the minimum total number of moves required so that all elements in nums become equal.
*/

/* Problem Link
https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxE=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++) maxE=max(maxE, nums[i]);
        int count=0;
        for(int i:nums) count+=(maxE-i);
        return count;
    }
};