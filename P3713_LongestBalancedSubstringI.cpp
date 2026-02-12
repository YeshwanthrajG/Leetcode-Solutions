/* 
Problem ID : 3713 

Problem : Longest Balanced Substring I

Statement : You are given a string s consisting of lowercase English letters.

A substring of s is called balanced if all distinct characters in the substring appear the 
same number of times.

Return the length of the longest balanced substring of s.
*/

/* Problem Link
https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12
*/

class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int maxL=0;
        for(int i=0;i<n;i++){
            int freq[26]={};
            int maxF=0, dist=0;
            for(int j=i;j<n;j++){
                int idx=s[j]-'a';
                dist+=(freq[idx]==0);
                maxF=max(maxF, ++freq[idx]);
                if(j-i+1==dist*maxF) maxL=max(maxL, j-i+1);
            }
        }
        return maxL;
    }
};