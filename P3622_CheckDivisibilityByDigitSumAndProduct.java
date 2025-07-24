/* 
Problem ID : 3622 

Problem : Check Divisibility by Digit Sum and Product

Statement : You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

The digit sum of n (the sum of its digits).

The digit product of n (the product of its digits).

Return true if n is divisible by this sum; otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/
*/

class Solution {
    public boolean checkDivisibility(int n) {
        int[] res=new int[2];
        findDigitsSumAndProduct(n,res);
        if(n%(res[0]+res[1])==0)    return true;
        return false;
    }
    private int[] findDigitsSumAndProduct(int n, int[] res){
        res[0]=0;
        res[1]=1;
        while(n>0){
            res[0]+=n%10;
            res[1]*=n%10;
            n/=10;
        }
        return res;
    }
}