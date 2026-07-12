/* 
Problem ID : 1331 

Problem : Rank Transform of an Array

Statement : Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
*/

/* Problem Link
https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2026-07-12
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res=arr;
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]=lower_bound(res.begin(), res.end(), arr[i])-res.begin()+1;
        }
        return arr;
    }
};