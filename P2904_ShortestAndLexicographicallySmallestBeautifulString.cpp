/* 
Problem ID : 2904 

Problem : Shortest and Lexicographically Smallest Beautiful String

Statement : You are given a binary string s and a positive integer k.

A substring of s is beautiful if the number of 1's in it is exactly k.

Let len be the length of the shortest beautiful substring.

Return the lexicographically smallest beautiful substring of string s with length equal to len. 
If s doesn't contain a beautiful substring, return an empty string.

A string a is lexicographically larger than a string b (of the same length) if in the first position 
where a and b differ, a has a character strictly larger than the corresponding character in b.

For example, "abcd" is lexicographically larger than "abcc" because the first position they differ 
is at the fourth character, and d is greater than c.
*/

/* Problem Link
https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/?envType=daily-question&envId=2026-08-26
*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        string res="";
        for(int i=0;i<n;i++){
            int ones=0;
            string curr="";
            for(int j=i;j<n;j++){
                curr+=s[j];
                if(s[j]=='1') ones++;
                if(ones>k) break;
                if(ones==k){
                    if(res=="" || curr.size()<res.size() || (curr.size()==res.size() && curr<res)) res=curr;
                }
            }
        }
        return res;
    }
};