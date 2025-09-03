/* 
Problem ID : 36 

Problem : Valid Sudoku

Statement : Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

/* Problem Link
https://leetcode.com/problems/valid-sudoku/description/?envType=daily-question&envId=2025-08-30
*/

class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;i++){
            Set<Character> set=new HashSet<>();
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(set.contains(board[i][j]))   return false;
                    set.add(board[i][j]);
                }
            }
        }
        for(int i=0;i<9;i++){
            Set<Character> set=new HashSet<>();
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(set.contains(board[j][i]))   return false;
                    set.add(board[j][i]);
                }
            }
        }
        for (int row = 0; row < 9; row += 3) {
    for (int col = 0; col < 9; col += 3) {
        Set<Character> set = new HashSet<>();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[row + i][col + j];
                if (c != '.') {
                    if (set.contains(c)) return false;
                    set.add(c);
                }
            }
        }
    }
}

        return true;
    }
}