/* 
Problem ID : 1091 

Problem : Smallest Subsequence of Distinct Characters

Statement : Given a string s, return the lexicographically smallest subsequence of s that contains 
all the distinct characters of s exactly once.
*/

/* Problem Link
https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> bit(26);
        int n=s.length();
        for(int i=0;i<n;i++){
            bit[s[i]-'a']=i;
        }
        vector<bool> st(26, false);
        string str;
        for(int i=0;i<n;i++){
            if(st[s[i]-'a']) continue;
            while(!str.empty() && str.back()>s[i] && bit[str.back()-'a']>i){
                st[str.back()-'a']=false;
                str.pop_back();
            }
            str.push_back(s[i]);
            st[s[i]-'a']=true;
        }
        return str;
    }
};