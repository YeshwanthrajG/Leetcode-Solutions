/* 
Problem ID : 2520 

Problem : Count the Digits That Divide a Number

Statement : Given an integer num, return the number of digits in num that divide num.

An integer val divides nums if nums % val == 0.
*/

/* Problem Link
https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int countDigits(int num) {
        int n=num;
        int count=0;
        while(n>0){
            int temp=n%10;
            if(num%temp==0) count++;
            n/=10;
        }
        return count++;
    }
};