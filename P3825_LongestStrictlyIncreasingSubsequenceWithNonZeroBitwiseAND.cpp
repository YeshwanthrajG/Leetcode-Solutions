/* 
Problem ID : 3825 

Problem : Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND

Statement : You are given an integer array nums.

Return the length of the longest strictly increasing subsequence in nums whose bitwise AND is non-zero. 
If no such subsequence exists, return 0.
*/

/* Problem Link
https://leetcode.com/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and/description/
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res=0;
        for(int b=0;b<=30;b++){
            vector<int> l;
            for(int x:nums){
                if(x&(1<<b)){
                    auto it=lower_bound(l.begin(), l.end(), x);
                    if(it==l.end()){
                        l.push_back(x);
                    }
                    else{
                        *it=x;
                    }
                }
            
            }
                res=max(res, (int)l.size());
        }
            return res;
    }
};