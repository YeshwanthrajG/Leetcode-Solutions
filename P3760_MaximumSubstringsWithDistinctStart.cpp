/* 
Problem ID : 3760 

Problem : Maximum Substrings With Distinct Start

Statement : You are given a string s consisting of lowercase English letters.

Return an integer denoting the maximum number of substrings you can split s into such that each substring 
starts with a distinct character (i.e., no two substrings start with the same character).
*/

/* Problem Link
https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/
*/

class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> seen(26,false);
        int count=0;
        for(char c:s){
            if(!seen[c-'a']){
                seen[c-'a']=true;
                count++;
            }
        }
        return count;
    }
};