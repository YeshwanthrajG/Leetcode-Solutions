/* 
Problem ID : 448 

Problem : Find All Numbers Disappeared in an Array

Statement : Given an array nums of n integers where nums[i] is in the range [1, n], return an array of 
all the integers in the range [1, n] that do not appear in nums.
*/

/* Problem Link
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int temp=abs(nums[i]);
            nums[temp-1]=-abs(nums[temp-1]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};