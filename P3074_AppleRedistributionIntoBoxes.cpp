/* 
Problem ID : 3074 

Problem : Apple Redistribution into Boxes

Statement : You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the 
ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.
*/

/* Problem Link
https://leetcode.com/problems/apple-redistribution-into-boxes/description/?envType=daily-question&envId=2025-12-24
*/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int res=0;
        int sum=0;
        sort(capacity.begin(), capacity.end(), greater<>());
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
        while(sum>0){
            sum-=capacity[res];
            res++;
        }
        return res;
    }
};