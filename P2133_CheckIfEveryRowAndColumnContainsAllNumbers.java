/* 
Problem ID : 2133 

Problem : Check if Every Row and Column Contains All Numbers

Statement : An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/
*/

class Solution {
    public boolean checkValid(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        for(int i=0;i<n;i++){
            Set<Integer> set=new HashSet<>();
            for(int j=0;j<m;j++){
                set.add(matrix[i][j]);
            }
            if(set.size()<n)    return false;
        }
        for(int i=0;i<n;i++){
            Set<Integer> set=new HashSet<>();
            for(int j=0;j<m;j++){
                set.add(matrix[j][i]);
            }
            if(set.size()<n)    return false;
        }
        return true;
    }
}