/* 
Problem ID : 2540 

Problem : Minimum Common Value

Statement : Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum 
integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence 
of that integer.
*/

/* Problem Link
https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        int n=nums1.size(), m=nums2.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]) return nums1[i];
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return -1;
    }
};