/* 
Problem ID : 696 

Problem : Count Binary Substrings

Statement : Given a binary string s, return the number of non-empty substrings that have the 
same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.
*/

/* Problem Link
https://leetcode.com/problems/count-binary-substrings/description/?envType=daily-question&envId=2026-02-19
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res=0, prev=0, sub=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) sub++;
            else{
                prev=sub;
                sub=1;
            }
            if(sub<=prev) res++;
        }
        return res;
    }
};