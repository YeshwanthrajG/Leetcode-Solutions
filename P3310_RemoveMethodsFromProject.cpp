/* 
Problem ID : 3310 

Problem : Remove Methods From Project

Statement : You are maintaining a project that has n methods numbered from 0 to n - 1.

You are given two integers n and k, and a 2D integer array invocations, where invocations[i] 
= [ai, bi] indicates that method ai invokes method bi.

There is a known bug in method k. Method k, along with any method invoked by it, either directly or 
indirectly, are considered suspicious and we aim to remove them.

A group of methods can only be removed if no method outside the group invokes any methods within it.

Return an array containing all the remaining methods after removing all the suspicious methods. 
You may return the answer in any order. If it is not possible to remove all the suspicious methods, 
none should be removed.
*/

/* Problem Link
https://leetcode.com/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05
*/

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> G(n);
        vector<int> v(n);
        queue<int> q;
        q.push(k);
        v[k]=1;
        for(auto &e:invocations){
            G[e[0]].push_back(e[1]);
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(int b:G[a]){
                if(!v[b]){
                    v[b]=1;
                    q.push(b);
                }
            }
        }
        for(auto &e:invocations){
            if(!v[e[0]] && v[e[1]]){
                vector<int> res;
                for(int i=0;i<n;i++) res.push_back(i);
                return res;
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(!v[i]) res.push_back(i);
        }
        return res;
    }
};