/* 
Problem ID : 3120 

Problem : Count the Number of Special Characters I

Statement : You are given a string word. A letter is called special if it appears both in lowercase and 
uppercase in word.

Return the number of special letters in word.
*/

/* Problem Link
https://leetcode.com/problems/count-the-number-of-special-characters-i/description/?envType=daily-question&envId=2026-05-26
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> map;
        for(char c:word) map[c]++;
        int cnt=0;
        for(auto &e:map){
            int k=e.first;
            if(map[toupper(k)]>0 && map[tolower(k)]>0){
                cnt++;
                map[toupper(k)]=0;
                map[tolower(k)]=0;
            }
        }
        return cnt;
    }
};