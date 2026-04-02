/* 
Problem ID : 3803 

Problem : Count Residue Prefixes

Statement : You are given a string s consisting only of lowercase English letters.

A prefix of s is called a residue if the number of distinct characters in the prefix is equal to 
len(prefix) % 3.

Return the count of residue prefixes in s.

A prefix of a string is a non-empty substring that starts from the beginning of the string and extends 
to any point within it.
*/

/* Problem Link
https://leetcode.com/problems/count-residue-prefixes/description/
*/

class Solution {
public:
    int residuePrefixes(string s) {
        vector<int> freq(26,0);
        int count=0;
        int res=0;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            if(freq[idx]==0) {
                count++;
            }
            freq[idx]++;
            int l=i+1;
            if(count==l%3){
                res++;
            }
        }
        return res;
        return res;
    }
};