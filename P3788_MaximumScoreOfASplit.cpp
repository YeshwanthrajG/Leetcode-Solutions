/* 
Problem ID : 3788 

Problem : Maximum Score of a Split

Statement : You are given an integer array nums of length n.

Choose an index i such that 0 <= i < n - 1.

For a chosen split index i:

Let prefixSum(i) be the sum of nums[0] + nums[1] + ... + nums[i].
Let suffixMin(i) be the minimum value among nums[i + 1], nums[i + 2], ..., nums[n - 1].
The score of a split at index i is defined as:

score(i) = prefixSum(i) - suffixMin(i)

Return an integer denoting the maximum score over all valid split indices.
*/

/* Problem Link
https://leetcode.com/problems/maximum-score-of-a-split/description/
*/

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<int> suffix(n);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=min(nums[i], suffix[i+1]);
        }
        long long prefixSum=0, ans=LLONG_MIN;
        for(int i=0;i<n-1;i++){
            prefixSum+=nums[i];
            long long score=prefixSum-suffix[i+1];
            ans=max(ans, score);
        }
        return ans;
    }
};