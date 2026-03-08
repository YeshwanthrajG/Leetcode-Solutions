/* 
Problem ID : 242 

Problem : Valid Anagram

Statement : Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/valid-anagram/description/
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> a(26,0);
        for(char c:s){
            a[c-'a']++;
        }
        for(char c:t){
            if(a[c-'a']==0) return false;
            a[c-'a']--;
        }
        return true;
    }
};