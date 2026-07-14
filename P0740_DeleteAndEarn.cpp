/* 
Problem ID : 740 

Problem : Delete and Earn

Statement : You are given an integer array nums. You want to maximize the number of points you get 
by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element 
equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.
*/

/* Problem Link
https://leetcode.com/problems/delete-and-earn/description/?envType=problem-list-v2&envId=w9kfviyj
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> res(n, 0);
        for(int n:nums){
            res[n]+=n;
        }
        int take=0, skip=0;
        for(int i=1;i<n;i++){
            int ti=skip+res[i];
            int si=max(skip, take);
            take=ti;
            skip=si;
        }
        return max(take, skip);
    }
};