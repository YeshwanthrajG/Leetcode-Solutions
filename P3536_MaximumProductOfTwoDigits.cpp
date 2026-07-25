/* 
Problem ID : 3536 

Problem : Maximum Product of Two Digits

Statement : You are given a positive integer n.

Return the maximum product of any two digits in n.

Note: You may use the same digit twice if it appears more than once in n.
*/

/* Problem Link
https://leetcode.com/problems/maximum-product-of-two-digits/description/?envType=daily-question&envId=2026-07-25
*/

class Solution {
public:
    int maxProduct(int n) {
        int max1=INT_MIN, max2=INT_MIN;
        while(n>0){
            int d=n%10;
            if(max1<=d){
                max2=max1;
                max1=d;
            }
            else if(max2<d){
                max2=d;
            }
            n/=10;
        }
        return (max1*max2);
    }
};