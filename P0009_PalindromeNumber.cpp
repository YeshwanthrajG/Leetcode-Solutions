/* 
Problem ID : 9 

Problem : Palindrome Number

Statement : Given an integer x, return true if x is a palindrome, and false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/palindrome-number/description/?envType=problem-list-v2&envId=w9kfviyj
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long num=x;
        long rev=0;
        while(num>0){
            rev*=10;
            rev+=num%10;
            num/=10;
        }
        cout<<rev;
        return rev==x;
    }
};