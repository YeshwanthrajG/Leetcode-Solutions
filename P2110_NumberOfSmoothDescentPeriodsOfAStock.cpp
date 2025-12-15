/* 
Problem ID : 2110 

Problem : Number of Smooth Descent Periods of a Stock

Statement : You are given an integer array prices representing the daily price history of a stock, 
where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each 
day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted 
from this rule.

Return the number of smooth descent periods.
*/

/* Problem Link
https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/?envType=daily-question&envId=2025-12-15
*/

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long res=1;
        int prev=1;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1){
                prev++;
            }
            else prev=1;
            res+=prev;
        }
        return res;
    }
};