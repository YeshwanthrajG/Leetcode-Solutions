/* 
Problem ID : 3809 

Problem : Best Reachable Tower

Statement : You are given a 2D integer array towers, where towers[i] = [xi, yi, qi] represents the 
coordinates (xi, yi) and quality factor qi of the ith tower.

You are also given an integer array center = [cx, cy​​​​​​​] representing your location, and an integer radius.

A tower is reachable if its Manhattan distance from center is less than or equal to radius.

Among all reachable towers:

Return the coordinates of the tower with the maximum quality factor.
If there is a tie, return the tower with the lexicographically smallest coordinate. If no tower is 
reachable, return [-1, -1].
The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
A coordinate [xi, yi] is lexicographically smaller than [xj, yj] if xi < xj, or xi == xj and yi < yj.

|x| denotes the absolute value of x.
*/

/* Problem Link
https://leetcode.com/problems/best-reachable-tower/description/
*/

class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n=towers.size();
        int maxQ=0;
        vector<int> res={INT_MAX, INT_MAX};
        for(int i=0;i<n;i++){
            int dist=abs(towers[i][0]-center[0])+abs(towers[i][1]-center[1]);
            if(dist<=radius){
                if(towers[i][2]>maxQ){
                    maxQ=towers[i][2];
                    res={towers[i][0], towers[i][1]};
                }
                else if(towers[i][2]==maxQ){
                    res=min(res, {towers[i][0], towers[i][1]});
                }
            }
        }
        if(res[0]==INT_MAX) return {-1, -1};
        return res;
    }
};