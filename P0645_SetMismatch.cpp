/* 
Problem ID : 645 

Problem : Set Mismatch

Statement : You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.
*/

/* Problem Link
https://leetcode.com/problems/set-mismatch/description/
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int rep=-1, miss=-1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) rep=nums[i];
            else if(nums[i]-nums[i-1]>1) miss=nums[i-1]+1;
        }
        if(miss==-1) {
            if(nums[0]!=1) miss=1;
            else miss=n;
        }
        return {rep, miss};
    }
};