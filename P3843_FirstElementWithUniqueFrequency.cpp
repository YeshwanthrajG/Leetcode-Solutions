/* 
Problem ID : 3843 

Problem : First Element with Unique Frequency

Statement : You are given an integer array nums.

Return an integer denoting the first element (scanning from left to right) in nums whose frequency is 
unique. That is, no other integer appears the same number of times in nums. If there is no such element, 
return -1.
*/

/* Problem Link
https://leetcode.com/problems/first-element-with-unique-frequency/description/
*/

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> freq;
        for(int i:nums){
            freq[i]++;
        }
        unordered_map<int, int> fCount;
        for(auto &i:freq){
            fCount[i.second]++;
        }
        for(int i:nums){
            if(fCount[freq[i]]==1){
                return i;
            }
        }
        return -1;
    }
};