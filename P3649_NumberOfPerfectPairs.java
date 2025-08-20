/* 
Problem ID : 3649 

Problem : Number of Perfect Pairs

Statement : You are given an integer array nums.

A pair of indices (i, j) is called perfect if the following conditions are satisfied:

i < j
Let a = nums[i], b = nums[j]. Then:
min(|a - b|, |a + b|) <= min(|a|, |b|)
max(|a - b|, |a + b|) >= max(|a|, |b|)
Return the number of distinct perfect pairs.

Note: The absolute value |x| refers to the non-negative value of x.
*/

/* Problem Link
https://leetcode.com/problems/number-of-perfect-pairs/description/
*/

class Solution {
    public long perfectPairs(int[] nums) {
        int n=nums.length;
        long count=0;

        int[] abs=new int[n];
        for(int i=0;i<n;i++){
            abs[i]=Math.abs(nums[i]);
        }
        Arrays.sort(abs);
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && abs[j]<=2L*abs[i]){
                j++;
            }
            count+=(j-i-1);
        }
        return count;
    }
}