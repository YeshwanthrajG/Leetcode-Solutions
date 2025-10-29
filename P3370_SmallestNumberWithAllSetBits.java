/* 
Problem ID : 3370 

Problem : Smallest Number With All Set Bits

Statement : You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary representation of x 
contains only set bits
*/

/* Problem Link
https://leetcode.com/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29
*/

class Solution {
    public int smallestNumber(int n) {
        int val=(int)Math.ceil((Math.log(n+1)/Math.log(2)));
        return (int)Math.pow(2,val)-1;
    }
}