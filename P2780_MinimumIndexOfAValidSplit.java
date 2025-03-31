/* 
Problem ID : 2780 

Problem : Minimum Index of a Valid Split

Statement : An element x of an integer array arr of length m is dominant if more than half the elements of arr 
have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is 
only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being 
inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-index-of-a-valid-split/?envType=daily-question&envId=2025-03-27
*/

class Solution {
    public int minimumIndex(List<Integer> list) {
        int n = list.size();
        int max = Integer.MIN_VALUE;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count == 0)
                max = list.get(i);
            if (max == list.get(i))
                count++;
            else
                count--;
        }
        count = 0;
        for (int num : list) {
            if (num == max)
                count++;
        }
        if (count <= (n - count) + 1)
            return -1;

        count = 0;
        for (int i = 0; i < n; i++) {
            if (list.get(i) == max)
                count++;
            else
                count--;
            if (count == 1)
                return i;
        }
        return -1;
    }
}