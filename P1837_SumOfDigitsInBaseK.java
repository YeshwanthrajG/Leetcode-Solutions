/* 
Problem ID : 1837 

Problem : Sum of Digits in Base K

Statement : Given an integer n (in base 10) and a base k, return the sum of the digits of n after 
converting n from base 10 to base k.

After converting, each digit should be interpreted as a base 10 number, and the sum should be returned in 
base 10.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-digits-in-base-k/description/
*/

class Solution {
    public int sumBase(int n, int k) {
        int res=0;
        while(n>0){
            res+=n%k;
            n/=k;
        }
        return res;
    }
}