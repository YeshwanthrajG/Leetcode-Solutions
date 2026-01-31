/* 
Problem ID : 744 

Problem : Find Smallest Letter Greater Than Target

Statement : You are given an array of characters letters that is sorted in non-decreasing order, 
and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a 
character does not exist, return the first character in letters.
*/

/* Problem Link
https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/?envType=daily-question&envId=2026-01-31
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=upper_bound(letters.begin(), letters.end(), target)-letters.begin();
        if(i==letters.size()) return letters[0];
        return letters[i];
    }
};