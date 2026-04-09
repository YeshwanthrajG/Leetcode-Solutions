/* 
Problem ID : 3 

Problem : Longest Substring Without Repeating Characters

Statement : Given a string s, find the length of the longest substring without duplicate characters.
*/

/* Problem Link
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int res=0, left=0;
        unordered_map<char, int> map;
        for(int i=0;i<n;i++){
            if(map.count(s[i])==0 || map[s[i]]<left){
                map[s[i]]=i;
                res=max(res, i-left+1);
            }
            else{
                left=map[s[i]]+1;
                map[s[i]]=i;
            }
        }
        return res;
    }
};