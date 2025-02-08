/* 
Problem ID : 628 

Problem : Maximum Product of Three Numbers

Statement : Given an integer array nums, find three numbers whose product is maximum and return the 
maximum product.
*/

/* Problem Link
https://leetcode.com/problems/maximum-product-of-three-numbers/description/?envType=problem-list-v2&envId=sorting
*/

class MaximumProductOfThreeNumbers {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        int result=Math.max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
        return result;
    }
}