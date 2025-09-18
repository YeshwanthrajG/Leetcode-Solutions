/* 
Problem ID : 2210 

Problem : Count Hills and Valleys in an Array

Statement : You are given a 0-indexed integer array nums. An index i is part of a hill in nums if the closest non-equal 
neighbors of i are smaller than nums[i]. Similarly, an index i is part of a valley in nums if the closest non-equal 
neighbors of i are larger than nums[i]. Adjacent indices i and j are part of the same hill or valley if nums[i] == nums[j].

Note that for an index to be part of a hill or valley, it must have a non-equal neighbor on both the left and 
right of the index.

Return the number of hills and valleys in nums.
*/

/* Problem Link
https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/?envType=daily-question&envId=2025-09-18
*/

class Solution {
    public int countHillValley(int[] nums) {
        int hill=0,valley=0;
        // Set<Integer> set=new LinkedHashSet<>();
        // for(int i:nums){
        //     set.add(i);
        // }
        // List<Integer> resList=new ArrayList<>(set);
        // System.out.println(resList);
        for(int i=1;i<nums.length-1;i++){
            if(nums[i]!=nums[i+1]){
                if((nums[i]>nums[hill] && nums[i]>nums[i+1]) ||
                (nums[i]<nums[hill] && nums[i]<nums[i+1])){
                    valley++;
                }
                hill=i;
            }
        }
        return valley;
    }
}