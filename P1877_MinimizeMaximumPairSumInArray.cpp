/* 
Problem ID : 1877 

Problem : Minimize Maximum Pair Sum in Array

Statement : The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair 
sum in a list of pairs.

For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be 
max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

Each element of nums is in exactly one pair, and
The maximum pair sum is minimized.
Return the minimized maximum pair sum after optimally pairing up the elements.
*/

/* Problem Link
https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2026-01-28
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int min = INT_MAX, max = INT_MIN;
        int freq[100001] = {0};
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < min) min = nums[i];
            if(nums[i] > max) max = nums[i];
            freq[nums[i]]++;
        }
        int max_sum = 0, l = min, r = max;
        while(l <= r) {
            if(freq[l] == 0) l++;
            else if(freq[r] == 0) r--;
            else {
                max_sum = fmax(max_sum, l + r);
                freq[l]--;
                freq[r]--;
            }
        }
        return max_sum;
    }
};