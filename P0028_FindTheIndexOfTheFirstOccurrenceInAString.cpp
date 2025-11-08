/* 
Problem ID : 28 

Problem : Find the Index of the First Occurrence in a String

Statement : Given two strings needle and haystack, return the index of the first 
occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

/* Problem Link
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length()<needle.length()) return -1;
        for(int i=0;i<=haystack.length()-needle.length();i++){
            if(haystack.substr(i, needle.length())==needle){
                return i;
            }
        }
        return -1;
    }
};