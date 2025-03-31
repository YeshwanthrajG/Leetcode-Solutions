/* 
Problem ID : 2033 

Problem : Minimum Operations to Make a Uni-Value Grid

Statement : You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to 
or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1. 
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2025-03-26
*/

import java.util.*;

class Solution {
    public int minOperations(int[][] grid, int x) {
        List<Integer> all = new ArrayList<>();
        
        for (int[] row : grid) {
            for (int num : row) {
                all.add(num);
            }
        }
        
        int mod = all.get(0) % x;
        for (int num : all) {
            if (num % x != mod) return -1;
        }

        Collections.sort(all);
        int median = all.get(all.size() / 2);
        int operations = 0;

        for (int num : all) {
            operations += Math.abs(num - median) / x;
        }

        return operations;
    }
}