/* 
Problem ID : 3767 

Problem : Maximize Points After Choosing K Tasks

Statement : You are given two integer arrays, technique1 and technique2, each of length n, where n 
represents the number of tasks to complete.

If the ith task is completed using technique 1, you earn technique1[i] points.
If it is completed using technique 2, you earn technique2[i] points.
You are also given an integer k, representing the minimum number of tasks that must be completed using 
technique 1.

You must complete at least k tasks using technique 1 (they do not need to be the first k tasks).

The remaining tasks may be completed using either technique.

Return an integer denoting the maximum total points you can earn.
*/

/* Problem Link
https://leetcode.com/problems/maximize-points-after-choosing-k-tasks/description/
*/

class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n=technique1.size();
        vector<pair<int,int>> both(n);
        for(int i=0;i<n;i++){
            both[i]={technique1[i]-technique2[i], i};
        }
        sort(both.begin(), both.end(), greater<>());
        // vector<bool> choosen(n,false);
        long long total=0;
        for(int i=0;i<k;i++){
            // choosen[both[i].second]=true;
            total+=technique1[both[i].second];
        }
        // cout<<total<<" ";
        for(int i=k;i<n;i++){
            // int idx=both[i].second;
            // if(both[i].first>=0) choosen[idx]=true;
            if(both[i].first>=0) total+=technique1[both[i].second];
            else total+=technique2[both[i].second];
        }
        // for(int i=0;i<n;i++){
        //     if(choosen[i]) total+=technique1[i];
        //     else total+=technique2[i];
        // }
        return total;
    }
};