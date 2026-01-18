/* 
Problem ID : 70 

Problem : Climbing Stairs

Statement : You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/* Problem Link
https://leetcode.com/problems/climbing-stairs?envType=problem-list-v2&envId=w9kfviyj
*/

class Solution {
public:
    int climbStairs(int n) {
        int a=0,b=1,c;
        while(n--){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};