/* 
Problem ID : 3498 

Problem : Reverse Degree of a String

Statement : Given a string s, calculate its reverse degree.

The reverse degree is calculated as follows:

For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) 
with its position in the string (1-indexed).
Sum these products for all characters in the string.
Return the reverse degree of s.
*/

/* Problem Link
https://leetcode.com/problems/reverse-degree-of-a-string/description/?envType=daily-question&envId=2026-09-20
*/

class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            sum+=((i+1)*(26-(s[i]-'a')));
        }
        return sum;
    }
};