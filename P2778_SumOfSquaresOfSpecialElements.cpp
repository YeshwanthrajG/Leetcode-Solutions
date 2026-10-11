/* 
Problem ID : 2778 

Problem : Sum of Squares of Special Elements

Statement : You are given a 1-indexed integer array nums of length n.

An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.

Return the sum of the squares of all special elements of nums.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-squares-of-special-elements/description/?envType=daily-question&envId=2026-10-11
*/

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(n%(i+1)==0) sum+=(nums[i]*nums[i]);
        }
        return sum;
    }
};