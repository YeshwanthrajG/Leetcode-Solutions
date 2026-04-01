/* 
Problem ID : 3798 

Problem : Largest Even Number

Statement : You are given a string s consisting only of the characters '1' and '2'.

You may delete any number of characters from s without changing the order of the remaining characters.

Return the largest possible resultant string that represents an even integer. If there is 
no such string, return the empty string "".
*/

/* Problem Link
https://leetcode.com/problems/largest-even-number/description/
*/

class Solution {
public:
    string largestEven(string s) {
        while(!s.empty() && s.back()=='1') s.pop_back();
        return s;
    }
};