/* 
Problem ID : 2571 

Problem : Minimum Operations to Reduce an Integer to 0

Statement : You are given a positive integer n, you can do the following operation any number of times:

Add or subtract a power of 2 from n.
Return the minimum number of operations to make n equal to 0.

A number x is power of 2 if x == 2i where i >= 0.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/
*/

class Solution {
public:
    int minOperations(int n) {
        return __builtin_popcount(n^(n*3));
    }
};