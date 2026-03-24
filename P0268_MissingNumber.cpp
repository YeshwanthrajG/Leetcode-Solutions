/* 
Problem ID : 268 

Problem : Missing Number

Statement : Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.
*/

/* Problem Link
https://leetcode.com/problems/missing-number/description/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for(int i=0;i<n;i++){
            if(i!=nums[i]) return i;
        }
        return n;
    }
};