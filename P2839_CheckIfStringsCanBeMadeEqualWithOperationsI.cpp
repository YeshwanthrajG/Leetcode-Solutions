/* 
Problem ID : 2839 

Problem : Check if Strings Can be Made Equal With Operations I

Statement : You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=daily-question&envId=2026-03-29
*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        return ((s1[0]==s2[0] && s1[2]==s2[2]) ||
                (s1[0]==s2[2] && s1[2]==s2[0]))  &&
                ((s1[1]==s2[1] && s1[3]==s2[3])  ||
                (s1[1]==s2[3] && s1[3]==s2[1]));
    }
};