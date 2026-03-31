/* 
Problem ID : 3794 

Problem : Reverse String Prefix

Statement : You are given a string s and an integer k.

Reverse the first k characters of s and return the resulting string.
*/

/* Problem Link
https://leetcode.com/problems/reverse-string-prefix/description/
*/

class Solution {
public:
    string reversePrefix(string s, int k) {
        int i=0;
        while(i<k){
            swap(s[i++], s[--k]);
        }
        return s;
    }
};