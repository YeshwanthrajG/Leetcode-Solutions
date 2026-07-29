/* 
Problem ID : 2012 

Problem : Sum of Beauty in the Array

Statement : You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) 
the beauty of nums[i] equals:

2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
0, if none of the previous conditions holds.
Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2..
*/

/* Problem Link
https://leetcode.com/problems/sum-of-beauty-in-the-array/description/?envType=problem-list-v2&envId=n11ydiyj
*/

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int> minR(n, 0);
        minR[n-1]=nums[n-1];
        for(int i=n-2;i>=2;i--){
            minR[i]=min(minR[i+1], nums[i]);
        }
        int maxL=nums[0], res=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>maxL && nums[i]<minR[i+1]) res+=2;
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]) res++;
            maxL=max(maxL, nums[i]);
        }
        return res;
    }
};