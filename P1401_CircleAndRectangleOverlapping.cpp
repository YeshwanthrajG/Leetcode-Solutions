/* 
Problem ID : 1401 

Problem : Circle and Rectangle Overlapping

Statement : You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned 
rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left 
corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, 
check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.
*/

/* Problem Link
https://leetcode.com/problems/circle-and-rectangle-overlapping/description/?envType=daily-question&envId=2026-09-19
*/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a=max(x1, min(xCenter,x2))-xCenter;
        int b=max(y1, min(yCenter,y2))-yCenter;
        return ((a*a+b*b)<=(radius*radius));
    }
};