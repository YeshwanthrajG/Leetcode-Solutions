/* 
Problem ID : 2503 

Problem : Maximum Number of Points From Grid Queries

Statement : You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the 
matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point 
if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, 
down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are 
allowed to visit the same cell multiple times.

Return the resulting array answer.
*/

/* Problem Link
https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/?envType=daily-question&envId=2025-03-28
*/

class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int rows = grid.length, cols = grid[0].length;
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int n = queries.length;
        int[] result = new int[n];
        int[][] visited = new int[rows][cols];

        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        List<int[]> sortedQueries = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            sortedQueries.add(new int[]{queries[i], i});
        }
        sortedQueries.sort(Comparator.comparingInt(a -> a[0]));

        minHeap.offer(new int[]{grid[0][0], 0, 0});
        visited[0][0] = 1;
        int points = 0;

        for (int[] q : sortedQueries) {
            int queryVal = q[0], queryIdx = q[1];

            while (!minHeap.isEmpty() && minHeap.peek()[0] < queryVal) {
                int[] top = minHeap.poll();
                int row = top[1], col = top[2];
                points++;

                for (int[] dir : directions) {
                    int nr = row + dir[0], nc = col + dir[1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && visited[nr][nc] == 0) {
                        minHeap.offer(new int[]{grid[nr][nc], nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
            result[queryIdx] = points;
        }
        return result;
    }
}