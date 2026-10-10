/* 
Problem ID : 2333 

Problem : Minimum Sum of Squared Difference

Statement : You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

The sum of squared difference of arrays nums1 and nums2 is defined as the sum of 
(nums1[i] - nums2[i])2 for each 0 <= i < n.

You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by 
+1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at 
most k2 times.

Return the minimum sum of squared difference after modifying array nums1 at most k1 times and 
modifying array nums2 at most k2 times.

Note: You are allowed to modify the array elements to become negative integers.
*/

/* Problem Link
https://leetcode.com/problems/minimum-sum-of-squared-difference/description/?envType=daily-question&envId=2026-10-10
*/

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> dp(100001, 0);
        long long k=(long long)k1+k2;
        long long res=0;
        int maxV=0;
        for(int i=0;i<nums1.size();i++){
            int x=abs(nums1[i]-nums2[i]);
            dp[x]++;
            res+=x;
            maxV=max(maxV, x);
        }
        if(res<=k) return 0;
        for(int i=maxV;i>0 && k>0;i--){
            long long mv=min(k, (long long)dp[i]);
            dp[i]-=mv;
            dp[i-1]+=mv;
            k-=mv;
        }
        long long tot=0;
        for(int i=0;i<=maxV;i++) tot+=(long long)i*i*dp[i];
        return tot;
    }
};