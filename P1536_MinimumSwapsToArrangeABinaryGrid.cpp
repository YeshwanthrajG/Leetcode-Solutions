/* 
Problem ID : 1536 

Problem : Minimum Swaps to Arrange a Binary Grid

Statement : Given an n x n binary grid, in one step you can choose two adjacent rows of the grid 
and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
*/

/* Problem Link
https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int trail = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--)
                trail++;
            grid[i][0] = trail;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int j, req = n - 1 - i;
            for (j = 0; j < grid.size(); j++)
                if (grid[j][0] >= req) break;
            if (j == grid.size()) return -1;
            swaps += j;
            grid.erase(grid.begin() + j);
        }

        return swaps;
    }
};