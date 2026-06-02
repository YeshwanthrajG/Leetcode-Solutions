/* 
Problem ID : 2309 

Problem : Greatest English Letter in Upper and Lower Case

Statement : Given a string of English letters s, return the greatest English letter which occurs as 
both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such 
letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.
*/

/* Problem Link
https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/
*/

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> set(s.begin(), s.end());
        for(char c='Z';c>='A';c--){
            if((set.find(c)!=set.end()) && (set.find(tolower(c))!=set.end()))   return string(1, c);
        }
        return "";
    }
};