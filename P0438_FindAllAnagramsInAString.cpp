/* 
Problem ID : 438 

Problem : Find All Anagrams in a String

Statement : Given two strings s and p, return an array of 
all the start indices of p's anagrams in s. You may return the answer in any order.
*/

/* Problem Link
https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.length(), m=s.length();
        if(m<n) return {};
        vector<int> arr(26, 0);
        vector<int> pArr(26, 0);
        vector<int> res;
        for(char c:p) pArr[c-'a']++;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        if(arr==pArr) res.push_back(0);
        for(int i=n;i<m;i++){
            arr[s[i-n]-'a']--;
            arr[s[i]-'a']++;
            if(arr==pArr) res.push_back(i-n+1);
        }
        return res;
    }
};