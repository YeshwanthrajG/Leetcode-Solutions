/* 
Problem ID : 3289 

Problem : The Two Sneaky Numbers of Digitville

Statement : In the town of Digitville, there was a list of numbers called nums containing integers 
from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous 
numbers sneaked in an additional time, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an array of size two 
containing the two numbers (in any order), so peace can return to Digitville.
*/

/* Problem Link
https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31
*/

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        Set<Integer> set=new HashSet<>();
        int[] res=new int[2];
        int n=0;
        for(int i:nums){
            if(set.contains(i)){
                res[n++]=i;
                if(n==2) return res;
            }
            else{
                set.add(i);
            }
        }
        return res;
    }
}