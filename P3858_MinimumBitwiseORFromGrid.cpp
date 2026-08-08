/* 
Problem ID : 3858 

Problem : Minimum Bitwise OR From Grid

Statement : You are given a 2D integer array grid of size m x n.

You must select exactly one integer from each row of the grid.

Return an integer denoting the minimum possible bitwise OR of the selected integers from each row.
*/

/* Problem Link
https://leetcode.com/problems/minimum-bitwise-or-from-grid/description/
*/

class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int res=0;
        for(int i=30;i>=0;i--) {
            int test_mask=res|((1<<i)-1);
            bool pos=true;
            for(auto& row:grid) {
                bool row_ok=false;
                for(int val:row) {
                    if((val|test_mask)==test_mask) {
                        row_ok= true;
                        break;
                    }
                }
                if(!row_ok) {
                    pos=false;
                    break;
                }
            }
            if(!pos) {
                res|=(1 << i);
            }
        }
        return res;
    }
};