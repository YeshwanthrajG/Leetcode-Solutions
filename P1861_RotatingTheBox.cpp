/* 
Problem ID : 1861 

Problem : Rotating the Box

Statement : You are given an m x n matrix of characters boxGrid representing a side-view of a box. 
Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. 
Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. 
Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not 
affect the stones' horizontal positions.

It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.
*/

/* Problem Link
https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int r=boxGrid.size(), c=boxGrid[0].size();
        vector<vector<char>> res(c, vector<char>(r, '.'));
        for(int i=0;i<r;i++){
            int x=c-1;
            for(int j=c-1;j>=0;j--){
                if(boxGrid[i][j]=='*') {
                    res[j][r-1-i]='*';
                    x=j-1;
                }
                else if(boxGrid[i][j]=='#'){
                    res[x--][r-1-i]='#';
                }
            }
            return res;
        }
    }
};