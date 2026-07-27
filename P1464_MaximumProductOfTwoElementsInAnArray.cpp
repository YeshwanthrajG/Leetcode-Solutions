/* 
Problem ID : 1464 

Problem : Maximum Product of Two Elements in an Array

Statement : Given the array of integers nums, you will choose two different indices i and j of that 
array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/

/* Problem Link
https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2026-07-27
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=INT_MIN, max2=max1;
        for(int i:nums){
            if(i>=max1){
                max2=max1;
                max1=i;
            }
            else if(i>max2) max2=i;
        }
        return (max1-1)*(max2-1);
    }
};