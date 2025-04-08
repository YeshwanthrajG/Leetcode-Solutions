/* 
Problem ID : 3396 

Problem : Minimum Number of Operations to Make Elements in Array Distinct

Statement : You are given an integer array nums. You need to ensure that the elements in the array are distinct. 
To achieve this, you can perform the following operation any number of times:

Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all 
remaining elements.
Note that an empty array is considered to have distinct elements. Return the minimum number of operations 
needed to make the elements in the array distinct.
*/

/* Problem Link
https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08
*/

class Solution {
    public int minimumOperations(int[] nums) {
        int[] mpp = new int[101];
        for (int i = nums.length - 1; i >= 0; --i) {
            if (++mpp[nums[i]] > 1) 
                return (i + 3) / 3;
        }
        return 0;
    }
}