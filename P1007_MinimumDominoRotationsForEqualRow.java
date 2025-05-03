/* 
Problem ID : 1007 

Problem : Minimum Domino Rotations For Equal Row

Statement : In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/?envType=daily-question&envId=2025-05-03
*/

class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int n = tops.length, res = Integer.MAX_VALUE;
        int[] face = new int[7];
        for (int i = 0; i < n; i++) {
            face[tops[i]]++;
            if (bottoms[i] != tops[i]) face[bottoms[i]]++;
        }
        for (int x = 1; x <= 6; x++) {
            if (face[x] < n) continue;
            int maintainTop = 0, maintainBottom = 0;
            boolean possible = true;
            for (int i = 0; i < n; i++) {
                if (tops[i] != x && bottoms[i] != x) {
                    possible = false;
                    break;
                }
                if (tops[i] != x) maintainTop++;
                if (bottoms[i] != x) maintainBottom++;
            }
            if (possible) res = Math.min(res, Math.min(maintainTop, maintainBottom));
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}