/* 
Problem ID : 1680 

Problem : Concatenation of Consecutive Binary Numbers

Statement : Given an integer n, return the decimal value of the binary string formed by 
concatenating the binary representations of 1 to n in order, modulo 109 + 7.
*/

/* Problem Link
https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/?envType=daily-question&envId=2026-02-28
*/

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD=1e9+7;
        long long res=0;
        int bits=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0) bits++;
            res=((res<<bits)|i)%MOD;
        }
        return res;
    }
};