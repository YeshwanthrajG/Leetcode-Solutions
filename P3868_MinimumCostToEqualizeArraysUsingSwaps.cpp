/* 
Problem ID : 3868 

Problem : Minimum Cost to Equalize Arrays Using Swaps

Statement : You are given two integer arrays nums1 and nums2 of size n.

You can perform the following two operations any number of times on these two arrays:

Swap within the same array: Choose two indices i and j. Then, choose either to swap nums1[i] and 
nums1[j], or nums2[i] and nums2[j]. This operation is free of charge.
Swap between two arrays: Choose an index i. Then, swap nums1[i] and nums2[i]. This operation incurs a 
cost of 1.
Return an integer denoting the minimum cost to make nums1 and nums2 identical. If this is not possible, 
return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/description/
*/

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int, int> freq;
        for(int x:nums1) freq[x]++;
        for(int x:nums2) freq[x]++;
        for(auto &x:freq){
            if(x.second%2) return -1;
        }
        unordered_map<int, int> freq2;
        for(int x:nums1) freq2[x]++;
        int res=0;
        for(int x:nums2){
            if(freq2[x]>0) freq2[x]--;
            else res++;
        }
        return res/2;
    }
};