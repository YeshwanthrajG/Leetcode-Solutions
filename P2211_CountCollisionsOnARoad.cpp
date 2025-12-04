/* 
Problem ID : 2211 

Problem : Count Collisions on a Road

Statement : There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 
from left to right and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' 
denoting whether the ith car is moving towards the left, towards the right, or staying at its current 
point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:

When two cars moving in opposite directions collide with each other, the number of collisions increases 
by 2.
When a moving car collides with a stationary car, the number of collisions increases by 1.
After a collision, the cars involved can no longer move and will stay at the point where they collided. 
Other than that, cars cannot change their state or direction of motion.

Return the total number of collisions that will happen on the road.
*/

/* Problem Link
https://leetcode.com/problems/count-collisions-on-a-road/description/?envType=daily-question&envId=2025-12-04
*/

class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        if(n==1) return 0;
        int l=0, r=n-1;
        while(directions[l] =='L') l++;
        while(l<r && directions[r]=='R') r--;
        if(l>=r) return 0;
        int res=0;
        for( ; l<=r; l++){
            res+=directions[l]!='S';
        }
        return res;
    }
};