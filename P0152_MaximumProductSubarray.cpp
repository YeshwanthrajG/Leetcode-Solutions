/* 
Problem ID : 152 

Problem : Maximum Product Subarray

Statement : Given an integer array nums, find a subarray that has the largest product, and 
return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.
*/

/* Problem Link
https://leetcode.com/problems/maximum-product-subarray/description/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxV=INT_MIN;
        int prod=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prod*=nums[i];
            maxV=max(maxV, prod);
            if(prod==0) prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            maxV=max(maxV, prod);
            if(prod==0) prod=1;
        }
        return maxV;
    }
};