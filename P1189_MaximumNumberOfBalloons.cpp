/* 
Problem ID : 1189 

Problem : Maximum Number of Balloons

Statement : Given a string text, you want to use the characters of text to form as many instances of the 
word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.
*/

/* Problem Link
https://leetcode.com/problems/maximum-number-of-balloons/description/?envType=daily-question&envId=2026-06-22
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> map;
        for(char c:text){
            map[c]++;
        }
        int res=INT_MAX;
        string one_letter="ban";
        string two_letter="lo";
        for(char c:one_letter){
            res=min(res, map[c]);
        }
        for(char c:two_letter){
            res=min(res, (map[c])/2);
        }
        return res;
    }
};