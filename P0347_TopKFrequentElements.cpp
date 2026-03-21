/* 
Problem ID : 347 

Problem : Top K Frequent Elements

Statement : Given an integer array nums and an integer k, return the 
k most frequent elements. You may return the answer in any order.
*/

/* Problem Link
https://leetcode.com/problems/top-k-frequent-elements/description/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for(auto &e:m){
            freq[e.second].push_back(e.first);
        }
        vector<int> res;
        for(int i=freq.size()-1;i>=0;i--){
            for(int x:freq[i]){
                res.push_back(x);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};