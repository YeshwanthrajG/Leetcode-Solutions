/* 
Problem ID : 3612 

Problem : Process String with Special Operations I

Statement : You are given a string s consisting of lowercase English letters and the special characters: 
*, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.
*/

/* Problem Link
https://leetcode.com/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16
*/

class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char c:s){
            if(c=='*'){
                if(res.length()>0) res.pop_back();
            }
            else if(c=='#') res+=res;
            else if(c=='%') reverse(res.begin(), res.end());
            else res.push_back(c);
        }
        return res;
    }
};