/* 
Problem ID : 1922 

Problem : Count Good Numbers

Statement : A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd 
indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) 
at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, 
return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
*/

/* Problem Link
https://leetcode.com/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13
*/

class Solution {
    public int countGoodNumbers(long n) {
        if(n==1)    return 5;
        long even=(n+1)/2;
        long odd=n/2;
        long mod=1000000007;
        return (int)((helper(5,even,mod)*helper(4,odd,mod))%mod);
    }

    public long helper(long base,long expo,long mod){
        long ans = 1;
        while(expo>0)
        {
            if(expo%2==0)            
            {
                base = (base*base)%mod;
                expo = expo/2;
            }
            else{
                ans = (ans*base)%mod;
                expo-=1;
            }
        }
        return ans;
    }
}