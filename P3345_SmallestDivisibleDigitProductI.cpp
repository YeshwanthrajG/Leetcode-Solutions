/* 
Problem ID : 3345 

Problem : Smallest Divisible Digit Product I

Statement : You are given two integers n and t. Return the smallest number greater than or equal to n 
such that the product of its digits is divisible by t.
*/

/* Problem Link
https://leetcode.com/problems/smallest-divisible-digit-product-i/description/?envType=daily-question&envId=2026-08-06
*/

class Solution {
public:
    int digProd(int n){
        int res=1;
        while(n>0){
            res*=(n%10);
            n/=10;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        int i=n;
        int p=digProd(i);
        while(p%t!=0){
            i++;
            p=digProd(i);
        }
        return i;
    }
};