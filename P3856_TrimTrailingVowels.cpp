/* 
Problem ID : 3856 

Problem : Trim Trailing Vowels

Statement : You are given a string s that consists of lowercase English letters.

Return the string obtained by removing all trailing vowels from s.

The vowels consist of the characters 'a', 'e', 'i', 'o', and 'u'.
*/

/* Problem Link
https://leetcode.com/problems/trim-trailing-vowels/description/
*/

class Solution {
public:
    string trimTrailingVowels(string s) {
        while(!s.empty()){
            char last=s.back();
            if(last=='a' || last=='e' || last=='i' || last=='o' || last=='u')
                s.pop_back();
            else break;
        }
        return s;
    }
};