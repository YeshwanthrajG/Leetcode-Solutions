/* 
Problem ID : 2144 

Problem : Minimum Cost of Buying Candies With Discount

Statement : A shop is selling candies at a discount. For every two candies sold, the shop gives a third 
candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is less 
than or equal to the minimum cost of the two candies bought.

For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with 
costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the 
minimum cost of buying all the candies.
*/

/* Problem Link
https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=daily-question&envId=2026-06-01
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int sum=0;
        int n=cost.size();
        for(int i=0;i<n;i+=3){
            sum+=cost[i];
            if(i+1<cost.size()) sum+=cost[i+1];
        }
        return sum;
    }
};