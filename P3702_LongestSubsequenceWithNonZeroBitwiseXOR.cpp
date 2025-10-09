/* 
Problem ID : 3702 

Problem : Longest Subsequence With Non-Zero Bitwise XOR

Statement : You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. 
If no such subsequence exists, return 0.
*/

/* Problem Link
https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=nums.size();
        if(n==1 && nums[0]==0) return 0;
        bool flag=false;
        int x=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(nums[i]!=0){
                flag=true;
            }
        }
        if(!flag) return 0;
        if(x!=0) return n;
        else return n-1;
    }
};