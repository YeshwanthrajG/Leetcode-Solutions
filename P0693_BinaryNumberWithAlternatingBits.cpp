/* 
Problem ID : 693 

Problem : Binary Number with Alternating Bits

Statement : Given a positive integer, check whether it has alternating bits: namely, 
if two adjacent bits will always have different values.
*/

/* Problem Link
https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int a=n^(n>>1);
        return (a&(a+1))==0;
    }
};