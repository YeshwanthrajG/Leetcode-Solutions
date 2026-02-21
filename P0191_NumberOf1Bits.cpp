/* 
Problem ID : 191 

Problem : Number of 1 Bits

Statement : Given a positive integer n, write a function that returns the number of set bits in 
its binary representation (also known as the Hamming weight).
*/

/* Problem Link
https://leetcode.com/problems/number-of-1-bits/description/
*/

class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};