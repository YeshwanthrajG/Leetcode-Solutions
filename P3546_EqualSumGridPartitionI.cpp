/* 
Problem ID : 3546 

Problem : Equal Sum Grid Partition I

Statement : You are given an m x n matrix grid of positive integers. Your task is to determine 
if it is possible to make either one horizontal or one vertical cut on the grid such that:

Each of the two resulting sections formed by the cut is non-empty.
The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false.
*/

/* Problem Link
https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25
*/

class Solution {
public:
    bool check(vector<long long> &arr, long long total){
        long long left = arr[0], right = total - left;
        for (int i = 1; i < arr.size(); i++) {
            if (left == right)
                return true;
            else if (left > right)
                return false;
            left += arr[i];
            right -= arr[i];
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rs(m, 0), cs(n, 0);
        long long total=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = grid[i][j];
                rs[i] += temp;
                cs[j] += temp;
                total += temp;
            }
        }
        if(total%2) return false;
        if(check(rs, total)) return true;
        if(check(cs, total)) return true;
        return false;
    }
};