/* 
Problem ID : 2914 

Problem : Minimum Number of Changes to Make Binary String Beautiful

Statement : You are given a 0-indexed binary string s having an even length.

A string is beautiful if it's possible to partition it into one or more substrings such that:

Each substring has an even length.
Each substring contains only 1's or only 0's.
You can change any character in s to 0 or 1.

Return the minimum number of changes required to make the string s beautiful.
*/

/* Problem Link
https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2026-11-18
*/

class Solution {
public:
    int minChanges(string s) {
        int changes=0, n=s.length();
        for(int i=0;i<n;i+=2){
            if(s[i]!=s[i+1]){
                changes++;
            }
        }
        return changes;
    }
};