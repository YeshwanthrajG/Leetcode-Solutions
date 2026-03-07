/* 
Problem ID : 994 

Problem : Rotting Oranges

Statement : You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.
*/

/* Problem Link
https://leetcode.com/problems/rotting-oranges/description/
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int , int>> q;
        vector<vector<int>> vis=grid;
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==2) q.push({i,j});
                if(vis[i][j]==1) res++;
            }
        }
        if(q.empty()) return -1;
        if(res==0) return 0;
        int time=-1;
        vector<pair<int, int>> dir={{1,0}, {-1,0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx, dy]: dir){
                    int i=x+dx;
                    int j=y+dy;
                    if(i>=0 && i<n && j>=0 && j<m && vis[i][j]==1){
                        vis[i][j]=2;
                        res--;
                        q.push({i,j});
                    }
                }
            }
            time++;
        }
        if(res==0) return time;
        return -1;
    }
};