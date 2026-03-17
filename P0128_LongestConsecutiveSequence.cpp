/* 
Problem ID : 128 

Problem : Longest Consecutive Sequence

Statement : Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/

/* Problem Link
https://leetcode.com/problems/longest-consecutive-sequence/description/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int curr=1, l=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1) curr++;
                else {
                    l=max(l, curr);
                    curr=1;
                }
            }
        }
        return max(l, curr);
    }
};