/* 
Problem ID : 2180 

Problem : Count Integers With Even Digit Sum

Statement : Given a positive integer num, return the number of positive integers less than or equal 
to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.
*/

/* Problem Link
https://leetcode.com/problems/count-integers-with-even-digit-sum/description/
*/

class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }

    int countEven(int num) {
        int count=0;
        for(int i=2;i<=num;i++){
            if((digitSum(i)%2)==0) count++;
        }    
        return count;
    }
};