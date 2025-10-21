/* 
Problem ID : 3346 

Problem : Maximum Frequency of an Element After Performing Operations I

Statement : You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing the operations.
*/

/* Problem Link
https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int m=*max_element(nums.begin(), nums.end());
        int n=m+k+2;
        vector<int> f(n,0);
        for(int x:nums) f[x]++;
        vector<int> pre(n,0);
        pre[0]=f[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+f[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(f[i]==0 && numOperations==0) continue;
            int l=max(0,i-k), r=min(n-1, i+k);
            int res=pre[r]-(l>0?pre[l-1]:0);
            int adj=res-f[i];
            int val=f[i]+min(numOperations, adj);
            ans=max(ans,val);
        }
        return ans;
    }
};