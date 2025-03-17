/* 
Problem ID : 2206 

Problem : Divide Array Into Equal Pairs

Statement : You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.
*/

/* Problem Link
https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17
*/

import java.util.*;

class Solution {
    public boolean divideArray(int[] nums) {
        HashMap<Integer,Integer> map=new HashMap<>();

        for(int i:nums)
        {
            map.put(i,map.getOrDefault(i,0)+1);
        }
        for(Integer i:map.values())
        {
            if(i%2==1)
                return false;
        }
        return true;
    }
}