/* 
Problem ID : 1967 

Problem : Number of Strings That Appear as Substrings in Word

Statement : Given an array of strings patterns and a string word, return the number of strings in 
patterns that exist as a substring in word.

A substring is a contiguous sequence of characters within a string.
*/

/* Problem Link
https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/?envType=daily-question&envId=2026-06-29
*/

class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int res=0;
        for(String s:patterns){
            if(word.contains(s)) res++;
        }
        return res;
    }
}