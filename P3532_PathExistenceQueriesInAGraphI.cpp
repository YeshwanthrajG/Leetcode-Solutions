/* 
Problem ID : 3532 

Problem : Path Existence Queries in a Graph I

Statement : You are given an integer n representing the number of nodes in a graph, labeled from 
0 to n - 1.

You are also given an integer array nums of length n sorted in non-decreasing order, and an integer 
maxDiff.

An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] 
is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there 
exists a path between nodes ui and vi.

Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the 
ith query and false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/?envType=daily-question&envId=2026-07-09
*/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> arr(n);
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+(nums[i]-nums[i-1]>maxDiff);
        }
        vector<bool> res;
        for(auto &q:queries) res.push_back(arr[q[0]]==arr[q[1]]);
        return res;
    }
};