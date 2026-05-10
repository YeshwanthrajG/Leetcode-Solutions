/* 
Problem ID : 3839 

Problem : Number of Prefix Connected Groups

Statement : You are given an array of strings words and an integer k.

Two words a and b at distinct indices are prefix-connected if a[0..k-1] == b[0..k-1].

A connected group is a set of words such that each pair of words is prefix-connected.

Return the number of connected groups that contain at least two words, formed from the given words.

Note:

Words with length less than k cannot join any group and are ignored.
Duplicate strings are treated as separate words.
*/

/* Problem Link
https://leetcode.com/problems/number-of-prefix-connected-groups/description/
*/

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> prefix;
        for(string &word : words){
            if(word.length()>=k){
                string p=word.substr(0,k);
                prefix[p]++;
            }
        }
        int groups=0;
        for(auto &[p, c]:prefix){
            if(c>=2){
                groups++;
            }
        }
        return groups;
    }
};