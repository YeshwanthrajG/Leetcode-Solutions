/* 
Problem ID : 3146 

Problem : Permutation Difference between Two Strings

Statement : You are given two strings s and t such that every character occurs at most once in s and t is 
a permutation of s.

The permutation difference between s and t is defined as the sum of the absolute difference between the 
index of the occurrence of each character in s and the index of the occurrence of the same character in t.

Return the permutation difference between s and t.
*/

/* Problem Link
https://leetcode.com/problems/permutation-difference-between-two-strings/description/
*/

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> map;
        int n=s.length();
        for(int i=0;i<n;i++){
            map[s[i]]=i;
        }
        int diff=0;
        for(int i=0;i<n;i++){
            diff+=(abs(i-map[t[i]]));
        }
        return diff;
    }
};