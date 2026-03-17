/* 
Problem ID : 49 

Problem : Group Anagrams

Statement : Given an array of strings strs, group the anagrams together. You can return the answer 
in any order.
*/

/* Problem Link
https://leetcode.com/problems/group-anagrams/description/
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto &x:strs){
            string k=x;
            sort(k.begin(), k.end());
            map[k].push_back(x);
        }
        vector<vector<string>> res;
        for(auto &e:map){
            res.push_back(e.second);
        }
        return res;
    }
};