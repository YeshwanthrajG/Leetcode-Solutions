/* 
Problem ID : 977 

Problem : Squares of a Sorted Array

Statement : Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.
*/

/* Problem Link
https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size=nums.size();
        vector<int> res;
        for(int i=0;i<size;i++){
            int n=nums[i]*nums[i];
            auto it=lower_bound(res.begin(), res.end(), n);
            res.insert(it, n);
        }
        return res;
    }
};