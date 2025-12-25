/* 
Problem ID : 3075 

Problem : Maximize Happiness of Selected Children

Statement : You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. 
You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been 
selected till now decreases by 1. Note that the happiness value cannot become negative and gets 
decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting 
k children.
*/

/* Problem Link
https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2025-12-25
*/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=max(0,(happiness[i]-i));
        }
        return sum;
    }
};