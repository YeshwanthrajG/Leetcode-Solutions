/* 
Problem ID : 1137 

Problem : N-th Tribonacci Number

Statement : The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/

/* Problem Link
https://leetcode.com/problems/n-th-tribonacci-number/description/
*/

class Solution {
public:
    int tribonacci(int n) {
        long long a=0, b=1, c=1, d;
        for(int i=0;i<n;i++){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return a;
    }
};