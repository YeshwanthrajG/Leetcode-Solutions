/* 
Problem ID : 1855 

Problem : Maximum Distance Between a Pair of Values

Statement : You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both 
i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.
*/

/* Problem Link
https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/?envType=problem-list-v2&envId=n11ydiyj
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=1;
        int n1=nums1.size(), n2=nums2.size();
        for(i=0;i<n1 && j<n2;j++){
            if(nums1[i]>nums2[j]) i++;
        }
        return j-i-1;
    }
};