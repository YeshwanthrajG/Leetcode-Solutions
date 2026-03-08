/* 
Problem ID : 2791 

Problem : Count Paths That Can Form a Palindrome in a Tree

Statement : You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted 
at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed 
array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, 
parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to the edge between 
i and parent[i]. s[0] can be ignored.

Return the number of pairs of nodes (u, v) such that u < v and the characters assigned to edges on the 
path from u to v can be rearranged to form a palindrome.

A string is a palindrome when it reads the same backwards as forwards.
*/

/* Problem Link
https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/
*/

class Solution {
public:
    int func(vector<int> &dp, vector<int> &parent, string &s, int i){
        if(i>0 && dp[i]==0){
            dp[i]=func(dp, parent, s, parent[i])^(1<<(s[i]-'a'));
        }
        return dp[i];
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();
        long long res=0;
        unordered_map<int, int> map;
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            int mask=func(dp, parent, s, i);
            for(int j=0;j<26;j++){
                res+=map.count(mask^(1<<j))?map[mask^(1<<j)]:0;
            }
            res+=map[mask]++;
        }
        return res;
    }
};