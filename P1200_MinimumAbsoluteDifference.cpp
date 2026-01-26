/* 
Problem ID : 1200 

Problem : Minimum Absolute Difference

Statement : Given an array of distinct integers arr, find all pairs of elements with the minimum 
absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
*/

/* Problem Link
https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        int minDiff=arr[1]-arr[0];
        for(int i=0;i<n-1;i++){
            minDiff=min(minDiff, arr[i+1]-arr[i]);
        }
        vector<vector<int>> res;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==minDiff){
                res.push_back({arr[i],arr[i+1]});
            }
        }
        return res;
    }
};