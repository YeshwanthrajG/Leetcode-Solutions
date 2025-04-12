/* 
Problem ID : 3066 

Problem : Minimum Operations to Exceed Threshold Value II

Statement : You are given a 0-indexed integer array nums, and an integer k.

You are allowed to perform some operations on nums, where in a single operation, you can:

Select the two smallest integers x and y from nums.
Remove x and y from nums.
Insert (min(x, y) * 2 + max(x, y)) at any position in the array.
Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13
*/

class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        for(int i:nums)
        {
            if(i<k)
                pq.add(i);
        }
        long x=0,y=0;
        int steps=0;
        while(!pq.isEmpty())
        {
            x=pq.poll();
            steps++;
            if(pq.isEmpty())
                break;
            y=pq.poll();
            long new_val=(long)x*2+y;
            if(new_val<k)
                pq.add((int)new_val);
        }
        return steps;
    }
}