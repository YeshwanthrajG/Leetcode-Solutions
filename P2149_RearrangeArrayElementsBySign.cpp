/* 
Problem ID : 2149 

Problem : Rearrange Array Elements by Sign

Statement : You are given a 0-indexed integer array nums of even length consisting of an equal number 
of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/

/* Problem Link
https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(int x:nums){
            if(x>0) pos.push_back(x);
            else neg.push_back(x);
        }
        vector<int> res;
        int n=pos.size(), m=neg.size();
        int i=0,j=0;
        bool toggle=true;
        while(i<n && j<m){
            if(toggle) res.push_back(pos[i++]);
            else res.push_back(neg[j++]);
            toggle=!toggle;
        }
        if(toggle && i<n) res.push_back(pos[i++]);
        if(!toggle && j<m) res.push_back(neg[j++]);
        return res;
    }
};