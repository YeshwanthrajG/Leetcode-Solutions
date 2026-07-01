/* 
Problem ID : 29 

Problem : Divide Two Integers

Statement : Given two integers dividend and divisor, divide two integers without using multiplication, 
division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 
8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed 
integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then 
return 231 - 1, and if the quotient is strictly less than -231, then return -231.
*/

/* Problem Link
https://leetcode.com/problems/divide-two-integers/description/
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        bool isNeg=false;
        if(dividend<0) isNeg=!isNeg;
        if(divisor<0) isNeg=!isNeg;
        long long a=llabs((long long)dividend);
        long long b=llabs((long long)divisor);
        long long res=0;
        while(a>=b){
            int quo=0;
            while(a>=(b<<(quo+1))) quo++;
            res+=(1LL<<quo);
            a-=(b<<quo);
        }
        return isNeg?-res:res;
    }
};