/* 
Problem ID : 3517 

Problem : Smallest Palindromic Rearrangement I

Statement : You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.
*/

/* Problem Link
https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/?envType=daily-question&envId=2026-07-28
*/

class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        int split=n/2;
        sort(s.begin(), s.begin()+split);
        for(int i=0;i<split;i++){
            s[n-i-1]=s[i];
        }
        return s;
    }
};