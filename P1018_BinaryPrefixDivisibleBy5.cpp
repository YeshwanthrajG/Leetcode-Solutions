/* 
Problem ID : 1018 

Problem : Binary Prefix Divisible By 5

Statement : You are given a binary array nums (0-indexed).

We define xi as the number whose binary representation is the subarray nums[0..i] 
(from most-significant-bit to least-significant-bit).
 
For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
Return an array of booleans answer where answer[i] is true if xi is divisible by 5.
*/

/* Problem Link
https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=daily-question&envId=2025-11-24
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int val = 0;
        for (int bit : nums) {
            val = (val * 2 + bit) % 5;
            ans.push_back(val == 0);
        }
        return ans;
    }
};