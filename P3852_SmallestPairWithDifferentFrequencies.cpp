/* 
Problem ID : 3852 

Problem : Smallest Pair With Different Frequencies

Statement : You are given an integer array nums.

Consider all pairs of distinct values x and y from nums such that:

x < y
x and y have different frequencies in nums.
Among all such pairs:

Choose the pair with the smallest possible value of x.
If multiple pairs have the same x, choose the one with the smallest possible value of y.
Return an integer array [x, y]. If no valid pair exists, return [-1, -1].
*/

/* Problem Link
https://leetcode.com/problems/smallest-pair-with-different-frequencies/description/
*/

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<int> a;
        for(auto &x:freq) a.push_back(x.first);
        sort(a.begin(), a.end());
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(freq[a[i]]!=freq[a[j]]){
                    return {a[i], a[j]};
                }
            }
        }
        return {-1, -1};
        
    }
};