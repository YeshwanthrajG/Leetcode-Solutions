/* 
Problem ID : 1991 

Problem : Find the Middle Index in Array

Statement : Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest 
amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + 
nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, 
the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.
*/

/* Problem Link
https://leetcode.com/problems/find-the-middle-index-in-array/description/
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n, 0), right(n, 0);
        for(int i=1;i<n;i++){
            left[i]=(left[i-1]+nums[i-1]);
        }
        for(int i=n-2;i>=0;i--) {
            right[i]=(right[i+1]+nums[i+1]);
        }
        for(int i=0;i<n;i++){
            if(left[i]==right[i]) return i;
        }
        return -1;
    }
};