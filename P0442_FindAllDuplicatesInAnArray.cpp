/* 
Problem ID : 442 

Problem : Find All Duplicates in an Array

Statement : Given an integer array nums of length n where all the integers of nums are in the range 
[1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding 
the space needed to store the output
*/

/* Problem Link
https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int temp=abs(nums[i]);
            if(nums[temp-1]<0) res.push_back(temp);
            nums[temp-1]*=-1;
        }
        return res;
    }
};