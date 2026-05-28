/* 
Problem ID : 520 

Problem : Detect Capital

Statement : We define the usage of capitals in a word to be right when one of the following cases 
holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.
*/

/* Problem Link
https://leetcode.com/problems/detect-capital/description/
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(isupper(word[i])) cnt++;
        }
        if(cnt==n) return true;
        else if(isupper(word[0])&& cnt==1) return true;
        else if(cnt==0) return true;
        return false;
    }
};