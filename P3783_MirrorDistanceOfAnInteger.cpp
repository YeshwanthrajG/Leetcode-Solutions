/* 
Problem ID : 3783 

Problem : Mirror Distance of an Integer

Statement : You are given an integer n.

Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by 
reversing the digits of n.

Return an integer denoting the mirror distance of n​​​​​​​.

abs(x) denotes the absolute value of x.
*/

/* Problem Link
https://leetcode.com/problems/mirror-distance-of-an-integer/description/
*/

class Solution {
public:
    int reverse(int n){
        int num=0;
        while(n>0){
            num=num*10+(n%10);
            n/=10;
        }
        return num;
    }
    int mirrorDistance(int n) {
        int r=reverse(n);
        return abs(r-n);
    }
};