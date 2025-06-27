/* 
Problem ID : 2652 

Problem : Sum Multiples

Statement : Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are 
undivisible by 3, 5, or 7.
Return an integer denoting the sum of all numbers in the given range satisfying the constraint.
*/

/* Problem Link
https://leetcode.com/problems/sum-multiples/description/
*/

class Solution {
    public int sumOfMultiples(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%3==0||i%5==0||i%7==0)
                sum+=i;
        }
        return sum;
    }
}