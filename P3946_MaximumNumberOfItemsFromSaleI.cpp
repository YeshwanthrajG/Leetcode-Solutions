/* 
Problem ID : 3946 

Problem : Maximum Number of Items From Sale I

Statement : You are given a 2D integer array items, where items[i] = [factori, pricei] represents the 
ith item. You are also given an integer budget.

There are unlimited copies of each item available for purchase.You may buy any number of copies of any 
items such that the total cost of the purchased copies is at most budget.

After buying items, you may receive free copies according to the following rules:

For each item i that you bought at least one copy of, you receive one free copy of every item j such 
that j != i and factori divides factorj.
Buying multiple copies of the same item i does not give additional free copies through item i.
The same item j can be received multiple times for free if it is received from purchases of different 
item types.
Return the maximum total number of item copies you can obtain, including both purchased copies and 
free copies, while spending at most budget on purchased items.
*/

/* Problem Link
https://leetcode.com/problems/maximum-number-of-items-from-sale-i/description/?envType=daily-question&envId=2026-11-27
*/

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> gain(n, 1);
        for(int i=0;i<n;i++){
            int f=items[i][0];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%f==0) cnt++;
            }
            gain[i]+=cnt;
        }
        int minP=INT_MAX;
        for(auto &x:items){
            minP=min(minP, x[1]);
        }
        vector<int> dp(budget+1, -1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int c=items[i][1];
            for(int b=budget;b>=c;b--){
                if(dp[b-c]!=-1) dp[b]=max(dp[b], dp[b-c]+gain[i]);
            }
        }
        int res=budget/minP;
        for(int i=0;i<=budget;i++){
            if(dp[i]==-1) continue;
            int rem=budget-i;
            res=max(res, dp[i]+rem/minP);
        }
        return res;
    }
};