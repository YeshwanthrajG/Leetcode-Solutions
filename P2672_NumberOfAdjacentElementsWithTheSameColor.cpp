/* 
Problem ID : 2672 

Problem : Number of Adjacent Elements With the Same Color

Statement : You are given an integer n representing an array colors of length n where all 
elements are set to 0's meaning uncolored. You are also given a 2D integer array queries 
where queries[i] = [indexi, colori]. For the ith query:

Set colors[indexi] to colori.
Count the number of adjacent pairs in colors which have the same color (regardless of colori).
Return an array answer of the same length as queries where answer[i] is the answer to the ith query.
*/

/* Problem Link
https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/
*/

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n,0), res;
        int i=0;
        for(auto q:queries){
            int idx=q[0], clr=q[1];
            int prev=(idx>0)?nums[idx-1]:0;
            int next=(idx<n-1)?nums[idx+1]:0;
            if(nums[idx]&&nums[idx]==prev) i--;
            if(nums[idx]&&nums[idx]==next) i--;
            nums[idx]=clr;
            if(nums[idx]==prev) i++;
            if(nums[idx]==next) i++;
            res.push_back(i);
        }
        return res;
    }
};