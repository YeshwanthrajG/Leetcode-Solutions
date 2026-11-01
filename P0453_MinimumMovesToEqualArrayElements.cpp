/* 
Problem ID : 453 

Problem : Minimum Moves to Equal Array Elements

Statement : Given an integer array nums of size n, return the minimum number of moves required to 
make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/?envType=daily-question&envId=2026-11-01
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minV=nums[0];
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            minV=min(minV, nums[i]);
            sum+=nums[i];
        }
        return (sum-(n*minV));
    }
};