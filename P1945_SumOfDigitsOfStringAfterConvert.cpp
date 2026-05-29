/* 
Problem ID : 1945 

Problem : Sum of Digits of String After Convert

Statement : You are given a string s consisting of lowercase English letters, and an integer k. Your 
task is to convert the string into an integer by a special process, and then transform it by summing its 
digits repeatedly k times. More specifically, perform the following steps:

Convert s into an integer by replacing each letter with its position in the alphabet (i.e. replace 'a' 
with 1, 'b' with 2, ..., 'z' with 26).
Transform the integer by replacing it with the sum of its digits.
Repeat the transform operation (step 2) k times in total.
For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/
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

    int getLucky(string s, int k) {
        int i=0, size=s.length();
        string num;
        for(char c:s) num+=c;
        int n=0;
        for(char c:num){
            int a=(c-'a')+1;
            n+=(a%10)+(a/10);
        }
        k--;
        int x=n;
        while(k--){
            n=digitSum(n);
            if(x==n) break;
            x=n;

        }
        return n;
    }
};