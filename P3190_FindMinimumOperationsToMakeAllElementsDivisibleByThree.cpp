/* 
Problem ID : 3190 

Problem : Find Minimum Operations to Make All Elements Divisible by Three

Statement : You are given an integer array nums. In one operation, you can add or subtract 1 
from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.
*/

/* Problem Link
https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/?envType=daily-question&envId=2025-11-22
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        for(auto& a:nums){
            if(a%3!=0) count++;
        }
        return count;
    }
};