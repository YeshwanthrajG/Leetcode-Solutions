/* 
Problem ID : 3573 

Problem : Best Time to Buy and Sell Stock V

Statement : You are given an integer array prices where prices[i] is the price of a stock in dollars 
on the ith day, and an integer k.

You are allowed to make at most k transactions, where each transaction can be either of the following:

Normal transaction: Buy on day i, then sell on a later day j where i < j. 
You profit prices[j] - prices[i].

Short selling transaction: Sell on day i, then buy back on a later day j where i < j. 
You profit prices[i] - prices[j].

Note that you must complete each transaction before starting another. 
Additionally, you can't buy or sell on the same day you are selling or buying back as part of a 
previous transaction.

Return the maximum total profit you can earn by making at most k transactions.
*/

/* Problem Link
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/?envType=daily-question&envId=2025-12-17
*/

struct State{
    long long maxProfit, buyHold, sellHold;
    State(long long p=0, long long b=0, long long s=0) : maxProfit(p), buyHold(b), sellHold(s) {}
};

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const int firstPrice=prices[0];
        vector<State> dp(k+1, State(0, -firstPrice, firstPrice));
        const int n=prices.size();
        for(int i=0;i<n;i++){
            const int currPrice=prices[i];
            for(int j=k;j>0;j--){
                auto& [profit, buy, sell]=dp[j];
                const long long prevProfit=dp[j-1].maxProfit;
                profit=max(profit, max(buy+currPrice, sell-currPrice));
                buy=max(buy, prevProfit-currPrice);
                sell=max(sell, prevProfit+currPrice);
            }
        }
        return dp[k].maxProfit;
    }
};