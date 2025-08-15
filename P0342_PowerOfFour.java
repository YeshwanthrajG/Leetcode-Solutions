/* 
Problem ID : 342 

Problem : Power of Four

Statement : Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.
*/

/* Problem Link
https://leetcode.com/problems/power-of-four/description/?envType=daily-question&envId=2025-08-15
*/

class Solution {
    public boolean isPowerOfFour(int n) {
        int e=(int)(Math.log(n)/Math.log(4));
        return (n>0 && (int)(Math.pow(4,e))%n==0);
    }
}