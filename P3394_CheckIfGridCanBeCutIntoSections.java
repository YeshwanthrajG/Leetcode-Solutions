/* 
Problem ID : 3394 

Problem : Check if Grid can be Cut into Sections

Statement : You are given an integer n representing the dimensions of an n x n grid, with the origin at the 
bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] 
is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined 
as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two 
horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/?envType=daily-question&envId=2025-03-25
*/

import java.util.*;

class Solution {
    public boolean checkValidCuts(int n, int[][] rectangles) {
        return canCut(rectangles, 0) || canCut(rectangles, 1);
    }

    private boolean canCut(int[][] rectangles, int axis) {
        Arrays.sort(rectangles, Comparator.comparingInt(a -> a[axis]));
        int cuts = 0, previousEnd = -1;

        for (int[] rect : rectangles) {
            int start = rect[axis], end = rect[axis + 2];

            if (start >= previousEnd) cuts++;
            previousEnd = Math.max(previousEnd, end);
            if (cuts >= 3) return true;
        }

        return false;
    }
}