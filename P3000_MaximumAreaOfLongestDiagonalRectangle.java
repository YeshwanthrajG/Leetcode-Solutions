/* 
Problem ID : 3000 

Problem : Maximum Area of Longest Diagonal Rectangle

Statement : You are given a 2D 0-indexed integer array dimensions.

For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents 
the width of the rectangle i.

Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, 
return the area of the rectangle having the maximum area.
*/

/* Problem Link
https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/?envType=daily-question&envId=2025-08-26
*/

class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxSq=Integer.MIN_VALUE;
        int maxVal=Integer.MIN_VALUE;
        for(int i=0;i<dimensions.length;i++){
            int sq=(dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]);
            if(sq>maxSq){
                maxSq=sq;
                maxVal=dimensions[i][0]*dimensions[i][1];
            }
            else if(sq==maxSq){
                maxVal=Math.max(maxVal,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return maxVal;
    }
}