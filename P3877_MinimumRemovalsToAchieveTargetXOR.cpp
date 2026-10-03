/* 
Problem ID : 3877 

Problem : Minimum Removals to Achieve Target XOR

Statement : You are given an integer array nums and an integer target.

You may remove any number of elements from nums (possibly zero).

Return the minimum number of removals required so that the bitwise XOR of the remaining elements equals target. If it is impossible to achieve target, return -1.

The bitwise XOR of an empty array is 0.
*/

/* Problem Link
https://leetcode.com/problems/minimum-removals-to-achieve-target-xor/description/
*/


class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        int m=n/2;
        vector<int> l(nums.begin(), nums.begin()+m);
        vector<int> r(nums.begin()+m, nums.end());
        unordered_map<int, int> m1, m2;
        int n1=l.size(), n2=r.size();

        for(int i=0;i<(1<<n1);i++){
            int x=0, cnt=0;
            for(int j=0;j<n1;j++){
                if(i&(1<<j)){
                    x^=l[j];
                    cnt++;
                }
            }
            m1[x]=max(m1[x], cnt);
        }
        for(int i=0;i<(1<<n2);i++){
            int x=0, cnt=0;
            for(int j=0;j<n2;j++){
                if(i&(1<<j)){
                    x^=r[j];
                    cnt++;
                }
            }
            m2[x]=max(m2[x], cnt);
        }
        int maxS=-1;
        for(auto &[x, cnt]:m1){
            int need=target^x;
            if(m2.count(need)) maxS=max(maxS, cnt+m2[need]);
        }
        if(maxS==-1) return -1;
        return n-maxS;
    }
};