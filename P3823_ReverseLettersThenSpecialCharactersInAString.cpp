/* 
Problem ID : 3823 

Problem : Reverse Letters Then Special Characters in a String

Statement : You are given a string s consisting of lowercase English letters and special characters.

Your task is to perform these in order:

Reverse the lowercase letters and place them back into the positions originally occupied by letters.
Reverse the special characters and place them back into the positions originally occupied by special 
characters.
Return the resulting string after performing the reversals.
*/

/* Problem Link
https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/description/
*/

class Solution {
public:
    string reverseByType(string s) {
        vector<char> r;
        vector<char> p;
        for(char c:s){
            if(c>='a' && c<='z') r.push_back(c);
            else p.push_back(c);
        }
        int j=r.size(),k=p.size();
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') s[i]=r[--j];
            else s[i]=p[--k];
        }
        return s;
    }
};