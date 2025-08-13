/* 
Problem ID : 326 

Problem : Power of Three

Statement : Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.
*/

/* Problem Link
https://leetcode.com/problems/power-of-three/description/?envType=daily-question&envId=2025-08-13
*/

class Solution {
    public boolean isPowerOfThree(int n) {
        int e=(int)(Math.log(Integer.MAX_VALUE)/Math.log(3));
        return (n>0 && (int)Math.pow(3,e)%n==0);
    }
}