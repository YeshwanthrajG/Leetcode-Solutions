/* 
Problem ID : 1015 

Problem : Smallest Integer Divisible by K

Statement : Given a positive integer k, you need to find the length of the smallest positive 
integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.
*/

/* Problem Link
https://leetcode.com/problems/smallest-integer-divisible-by-k/description/?envType=daily-question&envId=2025-11-25
*/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1) return 1;
        if(k%2==0 || k%5==0) return -1;
        int rem=0;
        for(int i=1;i<=k;i++){
            rem=(rem*10+1)%k;
            if(rem==0) return i;
        }
        return -1;
    }
};