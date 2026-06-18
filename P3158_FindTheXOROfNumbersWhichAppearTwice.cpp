/* 
Problem ID : 3158 

Problem : Find the XOR of Numbers Which Appear Twice

Statement : You are given an array nums, where each number in the array appears either once or twice.

Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.
*/

/* Problem Link
https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/
*/


class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int X=0;
        unordered_set<int> set;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(set.find(nums[i])!=set.end()) X^=nums[i];
            else set.insert(nums[i]);
        }
        return X;
    }
};