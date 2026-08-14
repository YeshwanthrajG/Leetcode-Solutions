/* 
Problem ID : 3090 

Problem : Maximum Length Substring With Two Occurrences

Statement : Given a string s, return the maximum length of a substring such that it contains at most 
two occurrences of each character.
*/

/* Problem Link
https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/?envType=daily-question&envId=2026-08-14
*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res=0;
        vector<int> freq(26, 0);
        for(int i=0, j=0;j<s.length();j++){
            freq[s[j]-'a']++;
            while(freq[s[j]-'a']>2){
                freq[s[i++]-'a']--;
            }
            res=max(res, j-i+1);
        }
        return res;
    }
};