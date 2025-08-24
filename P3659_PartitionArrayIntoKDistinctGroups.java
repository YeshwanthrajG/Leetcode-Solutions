/* 
Problem ID : 3659 

Problem : Partition Array Into K-Distinct Groups

Statement : You are given an integer array nums and an integer k.

Your task is to determine whether it is possible to partition all elements of nums into one or more groups such that:
Each group contains exactly k distinct elements.
Each element in nums must be assigned to exactly one group.
Return true if such a partition is possible, otherwise return false.
*/

/* Problem Link
https://leetcode.com/problems/partition-array-into-k-distinct-groups/description/
*/

class Solution {
    public boolean partitionArray(int[] nums, int k) {
        if(nums.length%k!=0) return false;
        Map<Integer,Integer> map=new HashMap<>();
        for(int i:nums){
            map.put(i,map.getOrDefault(i,0)+1);
        }
        int group=nums.length/k;

        for(int count:map.values()){
            if(count>group) return false;
        }
        return true;
    }
}