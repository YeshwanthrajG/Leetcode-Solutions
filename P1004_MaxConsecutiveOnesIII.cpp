/* 
Problem ID : 1004 

Problem : Max Consecutive Ones III

Statement : Given a binary array nums and an integer k, return 
the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/

/* Problem Link
https://leetcode.com/problems/max-consecutive-ones-iii/description/
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, maxL=0, zero=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            while(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }
            maxL=max(maxL, i-l+1);
        }
        return maxL;
    }
};