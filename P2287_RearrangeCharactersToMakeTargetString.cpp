/* 
Problem ID : 2287 

Problem : Rearrange Characters to Make Target String

Statement : You are given two 0-indexed strings s and target. You can take some letters from s and 
rearrange them to form new strings.

Return the maximum number of copies of target that can be formed by taking letters from s and 
rearranging them.
*/

/* Problem Link
https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/
*/

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> map1, map2;
        for(char c:target) map1[c]++;
        for(char c:s) map2[c]++;
        unordered_set<char> set(target.begin(), target.end());
        int res=INT_MAX;
        for(char c:set){
            res=min(res, (map2[c]/map1[c]));
        }
        return res;
    }
};