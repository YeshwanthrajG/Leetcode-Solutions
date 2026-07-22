/* 
Problem ID : 2404 

Problem : Most Frequent Even Element

Statement : Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.
*/

/* Problem Link
https://leetcode.com/problems/most-frequent-even-element/description/
*/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i:nums){
            if(i%2==0) map[i]++;
        }
        int freq=-1, val=-1;
        for(auto &[k,v]:map){
            if(v>val){
                freq=k;
                val=v;
            }
            if(val==v && freq>k){
                freq=k;
            }
        }
        return freq;
    }
};