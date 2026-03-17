/* 
Problem ID : 4 

Problem : Median of Two Sorted Arrays

Statement : Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

/* Problem Link
https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        for(int i=0;i<nums1.size();i++) arr.push_back(nums1[i]);
        for(int i=0;i<nums2.size();i++) arr.push_back(nums2[i]);
        sort(arr.begin(), arr.end());
        int n=arr.size();
        if(n%2==0){
            return (double)(arr[n/2-1]+arr[n/2])/2.0;
        }
        else return (double)(arr[n/2]);
    }
};