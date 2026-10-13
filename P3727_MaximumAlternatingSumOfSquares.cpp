/* 
Problem ID : 3727 

Problem : Maximum Alternating Sum of Squares

Statement : You are given an integer array nums. You may rearrange the elements in any order.

The alternating score of an array arr is defined as:

score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.
*/

/* Problem Link
https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/?envType=daily-question&envId=2026-10-13
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n;i++) nums[i]=abs(nums[i]);
        sort(nums.begin(), nums.end());
        for(int i=0;i<n/2;i++){
            res+=1LL*nums[n-i-1]*nums[n-i-1] - 1LL*nums[i]*nums[i];
        }
        if(n%2) res+=1LL*nums[n/2]*nums[n/2];
        return res;
    }
};