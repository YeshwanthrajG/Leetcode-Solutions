/* 
Problem ID : 3780 

Problem : Maximum Sum of Three Numbers Divisible by Three

Statement : You are given an integer array nums.

Your task is to choose exactly three integers from nums such that their sum is divisible by three.

Return the maximum possible sum of such a triplet. If no such triplet exists, return 0.
*/

/* Problem Link
https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/description/
*/

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> r0, r1, r2;
        for(int x: nums){
            int temp=x%3;
            if(temp==0) r0.push_back(x);
            else if(temp==1) r1.push_back(x);
            else r2.push_back(x);
        }
        sort(r0.rbegin(), r0.rend());
        sort(r1.rbegin(), r1.rend());
        sort(r2.rbegin(), r2.rend());
        int ans=0;
        if(r0.size()>=3){
            ans=max(ans, r0[0]+r0[1]+r0[2]);
        }
        if(r1.size()>=3){
            ans=max(ans, r1[0]+r1[1]+r1[2]);
        }
        if(r2.size()>=3){
            ans=max(ans, r2[0]+r2[1]+r2[2]);
        }
        if(!r0.empty() && !r1.empty() && !r2.empty()){
            ans=max(ans, r0[0]+r1[0]+r2[0]);
        }
        return ans;
    }
};