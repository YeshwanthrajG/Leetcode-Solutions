/* 
Problem ID : 2788 

Problem : Split Strings by Separator

Statement : Given an array of strings words and a character separator, split each string in words by 
separator.

Return an array of strings containing the new strings formed after the splits, excluding empty strings.

Notes

separator is used to determine where the split should occur, but it is not included as part of the 
resulting strings.
A split may result in more than two strings.
The resulting strings must maintain the same order as they were initially given.
*/

/* Problem Link
https://leetcode.com/problems/split-strings-by-separator/description/?envType=problem-list-v2&envId=n11ydiyj
*/

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        string word;
        for(string s:words){
            for(char c:s){
                if(c==separator){
                    if(word.length()){
                        res.push_back(word);
                        word.clear();
                    }
                }
                else word+=c;
            }
            if(word.length()){
                res.push_back(word);
                word.clear();
            }
        }
        return res;
    }
};