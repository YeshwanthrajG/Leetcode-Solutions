/* 
Problem ID : 796 

Problem : Rotate String

Statement : Given two strings s and goal, return true if and only if s can become goal after some number 
of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
*/

/* Problem Link
https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2026-05-03
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string c=goal+goal;
        if(c.find(s)!=-1) return true;
        return false;
    }
};