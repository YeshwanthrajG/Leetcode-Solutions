/* 
Problem ID : 3866 

Problem : First Unique Even Element

Statement : You are given an integer array nums.

Return an integer denoting the first even integer (earliest by array index) that appears exactly 
once in nums. If no such integer exists, return -1.

An integer x is considered even if it is divisible by 2.
*/

/* Problem Link
https://leetcode.com/problems/first-unique-even-element/
*/

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int num:nums){
            freq[num]++;
        }
        for(int x:nums){
            if(x%2==0 && freq[x]==1) return x;
        }
        return -1;
    }
};