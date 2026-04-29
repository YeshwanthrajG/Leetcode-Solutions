/* 
Problem ID : 3471 

Problem : Find the Largest Almost Missing Integer

Statement : You are given an integer array nums and an integer k.

An integer x is almost missing from nums if x appears in exactly one subarray of size k within nums.

Return the largest almost missing integer from nums. If no such integer exists, return -1.

A subarray is a contiguous sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/
*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        int largest=-1;
        int maxVal=-1;
        for(auto &e:map){
            if(e.second==1) maxVal=max(maxVal, e.first);
            largest=max(largest, e.first);
        }
        if(k==1){
            return maxVal;
        }
        else if(k==n){
            return largest;
        }
        else{
            if(map[nums[0]]==1 && map[nums[n-1]]==1) return max(nums[0], nums[n-1]);
            else if(map[nums[0]]==1) return nums[0];
            else if(map[nums[n-1]]==1) return nums[n-1];
        }
        return -1;
    }
};