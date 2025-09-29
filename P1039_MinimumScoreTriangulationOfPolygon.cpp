/* 
Problem ID : 1039 

Problem : Minimum Score Triangulation of Polygon

Statement : You have a convex n-sided polygon where each vertex has an integer value. 
You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices 
of each triangle must also be vertices of the original polygon. Note that no other shapes other than 
triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the 
values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 
triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.
*/

/* Problem Link
https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/?envType=daily-question&envId=2025-09-29
*/

class Solution {
public:
    int dp[50][50] = {};
    
    int minScoreTriangulation(vector<int>& values, int i = 0, int j = 0, int res = 0) {
        if (j == 0) j = values.size() - 1;
        if (dp[i][j] != 0) return dp[i][j];
        for (int k = i + 1; k < j; ++k) {
            res = min(res == 0 ? INT_MAX : res,
                minScoreTriangulation(values, i, k) + 
                values[i] * values[k] * values[j] + 
                minScoreTriangulation(values, k, j));
        }
        return dp[i][j] = res;
    }
};