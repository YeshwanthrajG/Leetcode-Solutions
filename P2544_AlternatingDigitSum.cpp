/* 
Problem ID : 2544 

Problem : Alternating Digit Sum

Statement : You are given a positive integer n. Each digit of n has a sign according 
to the following rules:

The most significant digit is assigned a positive sign.
Each other digit has an opposite sign to its adjacent digits.
Return the sum of all digits with their corresponding sign.
*/

/* Problem Link
https://leetcode.com/problems/alternating-digit-sum/description/
*/

class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> res;
        while(n>0){
            res.push_back(n%10);
            n/=10;
        }
        int m=res.size();
        int sum=0;
        bool sign=true;
        for(int i=m-1;i>=0;i--){
            if(sign) sum+=res[i];
            else sum-=res[i];
            sign=!sign;
        }
        return sum;
    }
};