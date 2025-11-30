/* 
Problem ID : 3754 

Problem : Concatenate Non-Zero Digits and Multiply by Sum I

Statement : You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. 
If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.
*/

/* Problem Link
https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0;
        long long sum=0;
        int i=0;
        string s=to_string(n);
        for(char c:s){
            if(c!='0') {
                num=num*10+(c-'0');
                sum+=(c-'0');
            }
        }
        return num*sum;
    }
};