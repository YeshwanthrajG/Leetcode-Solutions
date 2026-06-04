/* 
Problem ID : 3848 

Problem : Check Digitorial Permutation

Statement : You are given an integer n.

A number is called digitorial if the sum of the factorials of its digits is equal to the number itself.

Determine whether any permutation of n (including the original order) forms a digitorial number.

Return true if such a permutation exists, otherwise return false.

Note:

The factorial of a non-negative integer x, denoted as x!, is the product of all positive integers less 
than or equal to x, and 0! = 1.
A permutation is a rearrangement of all the digits of a number that does not start with zero. 
Any arrangement starting with zero is invalid.
*/

/* Problem Link
https://leetcode.com/problems/check-digitorial-permutation/description/
*/

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10, 1);
        for(int i=1;i<=9;i++){
            fact[i]=fact[i-1]*i;
        }
        int temp=n;
        int sum=0;
        while(temp>0){
            sum+=fact[temp%10];
            temp/=10;
        }
        string original=to_string(n);
        string found=to_string(sum);
        if(original.length()!=found.length()) return false;
        vector<int> f1(10,0), f2(10, 0);
        for(char c:original) f1[c-'0']++;
        for(char c:found) f2[c-'0']++;
        return f1==f2;
    }
};