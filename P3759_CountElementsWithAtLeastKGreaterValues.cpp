/* 
Problem ID : 3759 

Problem : Count Elements With at Least K Greater Values

Statement : You are given an integer array nums of length n and an integer k.

An element in nums is said to be qualified if there exist at least k elements in the array that 
are strictly greater than it.

Return an integer denoting the total number of qualified elements in nums.
*/

/* Problem Link
https://leetcode.com/problems/count-elements-with-at-least-k-greater-values/description/
*/

class Solution {
public:
    int upperBound(vector<int>& nums, int target){
        int l=0,r=nums.size();
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]<=target){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return l;
    }
    
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int idx=upperBound(nums,nums[i]);
            int greater=n-idx;
            if(greater>=k) ans++;
        }
        return ans;
    }
};