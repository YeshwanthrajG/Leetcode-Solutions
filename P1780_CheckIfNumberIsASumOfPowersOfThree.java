/* 
Problem ID : 1780 

Problem : Check if Number is a Sum of Powers of Three

Statement : Given an integer n, return true if it is possible to represent n as the sum of distinct 
powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.
*/

/* Problem Link
https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04
*/

class Solution {
    public boolean checkPowersOfThree(int n) {
        if(n==0)    return true;
        if(n%3==2)    return false;
        return checkPowersOfThree(n/3);
    }
}