/* 
Problem ID : 231 

Problem : Power of Two

Statement : Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
*/

/* Problem Link
https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2025-08-09
*/


// Solution 1
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n>0 && (n&n-1)==0;
    }
}

// Solution 2 
class Solution {
    public boolean isPowerOfTwo(int n) {
        int e=(int)(Math.log(n)/Math.log(2));
        return (n>0 && (int)(Math.pow(2,e))%n==0);
    }
}