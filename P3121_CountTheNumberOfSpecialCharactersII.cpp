/* 
Problem ID : 3121 

Problem : Count the Number of Special Characters II

Statement : You are given a string word. A letter c is called special if it appears both in lowercase 
and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence 
of c.

Return the number of special letters in word.
*/

/* Problem Link
https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/?envType=daily-question&envId=2026-05-27
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> smallLast, capitalFirst;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z') smallLast[word[i]]=i;
            else{
                char l=tolower(word[i]);
                if(capitalFirst.find(l)==capitalFirst.end()) capitalFirst[l]=i;
            }
        }
        int count=0;
        for(auto &[c, idx]: smallLast){
            if(capitalFirst.find(c)!=capitalFirst.end() && idx<capitalFirst[c]) count++;
        }
        return count;
    }
};