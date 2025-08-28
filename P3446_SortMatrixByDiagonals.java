/* 
Problem ID : 3446 

Problem : Sort Matrix by Diagonals

Statement : You are given an n x n square matrix of integers grid. Return the matrix such that:

The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.
*/

/* Problem Link
https://leetcode.com/problems/sort-matrix-by-diagonals/description/?envType=daily-question&envId=2025-08-28
*/

class Solution {
    public int[][] sortMatrix(int[][] grid) {
        Map<Integer,PriorityQueue<Integer>> diagonalMap=new HashMap<>();
        int m=grid.length;
        int n=grid[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int k=i-j;
                diagonalMap.putIfAbsent(k,(k<0)?new PriorityQueue<>():
                new PriorityQueue<>(Collections.reverseOrder()));
                diagonalMap.get(k).offer(grid[i][j]);
            }
        }

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int k=i-j;
                    grid[i][j]=diagonalMap.get(k).poll();
                }
            }
            return grid;
    }
}