/* 
Problem ID : 3487 

Problem : Maximum Unique Subarray Sum After Deletion

Statement : You are given an integer array nums.

You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, 
select a subarray of nums such that:

All elements in the subarray are unique.
The sum of the elements in the subarray is maximized.
Return the maximum sum of such a subarray.
*/

/* Problem Link
https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25
*/

class Solution {
    public int maxSum(int[] nums) {
        int max=Integer.MIN_VALUE;
        for(int i:nums){
            max=Math.max(max,i);
        }

        if(max<=0) return max;

        max=0;
        HashSet<Integer> set=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0)            
                set.add(nums[i]);
        }
        for(int i:set){
            if(i>0) 
                max+=i;
        }
        return max;
    }
}