/* 
Problem ID : 1356 

Problem : Sort Integers by The Number of 1 Bits

Statement : You are given an integer array arr. Sort the integers in the array in ascending order 
by the number of 1's in their binary representation and in case of two or more integers have the 
same number of 1's you have to sort them in ascending order.

Return the array after sorting it.
*/

/* Problem Link
https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=daily-question&envId=2026-02-25
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> buckets(33);
        for(int i=0;i<arr.size();i++){
            buckets[__builtin_popcount(arr[i])].push_back(arr[i]);
        }
        vector<int> res;
        for(int i=0;i<buckets.size();i++){
            sort(buckets[i].begin(), buckets[i].end());
            for(int j=0;j<buckets[i].size();j++) res.push_back(buckets[i][j]);
        }
        return res;
    }
};