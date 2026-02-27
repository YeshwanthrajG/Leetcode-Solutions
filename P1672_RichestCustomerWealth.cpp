/* 
Problem ID : 1672 

Problem : Richest Customer Wealth

Statement : You are given an m x n integer grid accounts where accounts[i][j] is the amount of 
money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest 
customer is the customer that has the maximum wealth.
*/

/* Problem Link
https://leetcode.com/problems/richest-customer-wealth/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxVal=0;
        int sum;
        for(int i=0;i<accounts.size();i++){
            sum=0;
            for(int j=0;j<accounts[0].size();j++){
                sum+=accounts[i][j]++;
            }
            maxVal=max(maxVal, sum);
        }
        return maxVal;
    }
};