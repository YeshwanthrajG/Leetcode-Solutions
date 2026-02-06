/* 
Problem ID : 3634 

Problem : Construct K Palindrome Strings

Statement : You are given an integer array nums and an integer k.

An array is considered balanced if the value of its maximum element is at most k 
times the minimum element.

You may remove any number of elements from nums​​​​​​​ without making it empty.

Return the minimum number of elements to remove so that the remaining array is balanced.

Note: An array of size 1 is considered balanced as its maximum and minimum are equal, 
and the condition always holds true.
*/

/* Problem Link
https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06
*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if(n==1) return 0;
        int count=0, start=0;
        for(int end=0;end<n;end++){
            while(nums[end]>(long)nums[start]*k) start++;
            count=max(count, end-start+1);
        }
        return n-count;
    }
};