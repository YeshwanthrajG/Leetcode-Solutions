/* 
Problem ID : 3898 

Problem : Find the Degree of Each Vertex

Statement : You are given a 2D integer array matrix of size n x n representing the adjacency matrix of 
an undirected graph with n vertices labeled from 0 to n - 1.

matrix[i][j] = 1 indicates that there is an edge between vertices i and j.
matrix[i][j] = 0 indicates that there is no edge between vertices i and j.
The degree of a vertex is the number of edges connected to it.

Return an integer array ans of size n where ans[i] represents the degree of vertex i.
*/

/* Problem Link
https://leetcode.com/problems/find-the-degree-of-each-vertex/description/
*/

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            int d=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1) d++;
            }
            res[i]=d;
        }
        return res;
    }
};