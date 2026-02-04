/* 
Problem ID : 3784 

Problem : Minimum Deletion Cost to Make All Characters Equal

Statement : You are given a string s of length n and an integer array cost of the same length, 
where cost[i] is the cost to delete the ith character of s.

You may delete any number of characters from s (possibly none), such that the resulting string is 
non-empty and consists of equal characters.

Return an integer denoting the minimum total deletion cost required.
*/

/* Problem Link
https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/description/
*/

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n=s.size();
        long long total=0;
        for(int c:cost){
            total+=c;
        }
        vector<long long> keep(26, 0);
        for(int i=0;i<n;i++){
            keep[s[i]-'a']+=cost[i];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<26;i++){
            ans=min(ans, total-keep[i]);
        }
        return ans;
    }
};