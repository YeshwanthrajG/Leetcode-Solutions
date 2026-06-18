/* 
Problem ID : 41 

Problem : First Missing Positive

Statement : Given an unsorted integer array nums. Return the smallest positive integer that is not 
present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
*/

/* Problem Link
https://leetcode.com/problems/first-missing-positive/description/
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k=1;
        for(int i:nums){
            if(i>0 && i==k) k++;
            else if(i>k) return k;
        }
        return k;
    }
};