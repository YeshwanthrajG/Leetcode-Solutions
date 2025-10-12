/* 
Problem ID : 3712 

Problem : Sum of Elements With Frequency Divisible by K

Statement : You are given an integer array nums and an integer k.

Return an integer denoting the sum of all elements in nums whose frequency is divisible by k, or 0 
if there are no such elements.

Note: An element is included in the sum exactly as many times as it appears in the array if its 
total frequency is divisible by k.

The frequency of an element x is the number of times it occurs in the array.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/description/
*/

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto &i:nums){
            map[i]++;
        }
        int res=0;
        for(auto &i:map){
            if(i.second%k==0){
                res+=(i.first*i.second);
            }
        }
        return res;
    }
};