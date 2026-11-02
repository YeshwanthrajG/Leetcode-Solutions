/* 
Problem ID : 462 

Problem : Minimum Moves to Equal Array Elements II

Statement : Given an integer array nums of size n, return the minimum number of moves required to 
make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.
*/

/* Problem Link
https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/?envType=daily-question&envId=2026-11-02
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int mid=nums[n/2];
        int moves=0;
        for(int i:nums){
            moves+=abs(i-mid);
        }
        return moves;
    }
};