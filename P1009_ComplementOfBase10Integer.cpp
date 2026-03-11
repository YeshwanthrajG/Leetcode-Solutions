/* 
Problem ID : 1009 

Problem : Complement of Base 10 Integer

Statement : The complement of an integer is the integer you get when you flip all the 0's to 1's and 
all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.
*/

/* Problem Link
https://leetcode.com/problems/complement-of-base-10-integer/description/?envType=daily-question&envId=2026-03-11
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int mask=0;
        int temp=n;
        while(temp){
            mask=(mask<<1)|1;
            temp>>=1;
        }
        return mask^n;
    }
};