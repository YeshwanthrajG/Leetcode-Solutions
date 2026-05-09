/* 
Problem ID : 3834 

Problem : Merge Adjacent Equal Elements

Statement : You are given an integer array nums.

You must repeatedly apply the following merge operation until no more changes can be made:

If any two adjacent elements are equal, choose the leftmost such adjacent pair in the current array and 
replace them with a single element equal to their sum.
After each merge operation, the array size decreases by 1. Repeat the process on the updated array until 
no more changes can be made.

Return the final array after all possible merge operations.
*/

/* Problem Link
https://leetcode.com/problems/merge-adjacent-equal-elements/description/
*/

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long> res;
        for(long long x:nums){
            while(!res.empty() && res.back()==x){
                res.pop_back();
                x=(long long)x*2;
            }
            res.push_back(x);
        }
        return res;
    }
};