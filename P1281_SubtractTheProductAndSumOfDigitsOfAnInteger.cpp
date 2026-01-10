/* 
Problem ID : 1281 

Problem : Subtract the Product and Sum of Digits of an Integer

Statement : Given an integer number n, return the difference between the product of its digits 
and the sum of its digits.
*/

/* Problem Link
https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        long long prod=1,sum=0;
        int num=n;
        while(num>0){
            int temp=num%10;
            prod*=temp;
            sum+=temp;
            num/=10;
        }
        return (prod-sum);
    }
};