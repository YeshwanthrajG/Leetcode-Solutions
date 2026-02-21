/* 
Problem ID : 762 

Problem : Prime Number of Set Bits in Binary Representation

Statement : Given two integers left and right, return the count of numbers in the inclusive 
range [left, right] having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has is the number of 1's present when written in binary.

For example, 21 written in binary is 10101, which has 3 set bits.
*/

/* Problem Link
https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/?envType=daily-question&envId=2026-02-21
*/

class Solution {
public:
    bool isPrime(int n){
        if(n<2) return false;
        if(n==2 || n==3){
            return true;
        }
        if(n%2==0 || n%3==0) return false;
        for(int i=5;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int res=0;
        for(int i=left;i<=right;i++){
            if(isPrime(__builtin_popcount(i))) res++;
        }
        return res;
    }
};