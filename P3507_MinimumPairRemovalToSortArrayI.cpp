/* 
Problem ID : 3507 

Problem : Minimum Pair Removal to Sort Array I

Statement : Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the 
leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous 
element (if it exists).
*/

/* Problem Link
https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22
*/

class Solution {
private:
    bool isSorted(vector<int>& nums, int n) {
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0, n = nums.size();
        while(!isSorted(nums, n)) {
            ans += 1;
            int min_sum = INT_MAX, pos = -1;
            for(int i = 1; i < n; i++) {
                int sum = nums[i - 1] + nums[i];
                if(sum < min_sum) {
                    min_sum = sum;
                    pos = i;
                }
            }
            nums[pos - 1] = min_sum;
            for(int i = pos; i < n - 1; i++) nums[i] = nums[i + 1];
            n--;
        }
        return ans;
    }
};