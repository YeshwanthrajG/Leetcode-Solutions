/* 
Problem ID : 3020 

Problem : Find the Maximum Number of Elements in Subset

Statement : You are given an array of positive integers nums.

You need to select a subset of nums which satisfies the following condition:

You can place the selected elements in a 0-indexed array such that it follows the pattern: 
[x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). 
For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions.
*/

/* Problem Link
https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/?envType=daily-question&envId=2026-06-27
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i:nums){
            map[i]++;
        }
        int res=(map[1]-1)|1;
        map.erase(1);
        for(auto &i:map){
            int n=0, temp=i.first;
            int sq=sqrt(temp);
            if((sq*sq)==map.count(sq)&&map[sq]>1) continue;
            while(temp<31623 && map.count(temp) && map[temp]>1){
                n+=2;
                temp*=temp;
            }
            res=fmax(res, n+((map.count(temp)<<1)-1));
        }
        return res;
    }
};