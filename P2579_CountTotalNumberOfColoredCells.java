/* 
Problem ID : 2579 

Problem : Count Total Number of Colored Cells

Statement : There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a 
positive integer n, indicating that you must do the following routine for n minutes:

At the first minute, color any arbitrary unit cell blue.
Every minute thereafter, color blue every uncolored cell that touches a blue cell.
Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.
*/

/* Problem Link
https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05
*/

class Solution {
    public long coloredCells(int n) {
        int i=0;
        long result=1;
        while(i<n)
        {
            result+=(4*i);
            i++;
        }
        return result;
    }
}