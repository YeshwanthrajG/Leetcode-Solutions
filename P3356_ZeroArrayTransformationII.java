/* 
Problem ID : 3356 

Problem : Zero Array Transformation II

Statement : You are given an integer array nums of length n and a 2D array queries where 
queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries 
in sequence, nums becomes a Zero Array. If no such k exists, return -1.
*/

/* Problem Link
https://leetcode.com/problems/zero-array-transformation-ii/description/?envType=daily-question&envId=2025-03-13
*/

class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        int n=nums.length;
        if(Arrays.stream(nums).allMatch(x->x==0))   return 0;
        int left=1,right=queries.length;
        if(!isZeroArrayPossible(right,nums,queries))    return -1;
        while(left<right)   
        {
            int mid=left+(right-left)/2;
            if(isZeroArrayPossible(mid,nums,queries))
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }

    private boolean isZeroArrayPossible(int x,int[] nums, int[][] queries)
    {
        int n=nums.length;
        int[] diff=new int[n+1];
        for(int i=0;i<x;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            diff[l]+=val;
            diff[r+1]-=val;
        }
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=diff[i];
            if(curr<nums[i])    return false;
        }
        return true;
    }
}