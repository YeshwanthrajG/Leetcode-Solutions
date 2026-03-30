/* 
Problem ID : 3789 

Problem : Minimum Cost to Acquire Required Items

Statement : You are given five integers cost1, cost2, costBoth, need1, and need2.

There are three types of items available:

An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
You must collect enough items so that the total contribution toward type 1 is at least need1 and 
the total contribution toward type 2 is at least need2.

Return an integer representing the minimum possible total cost to achieve these requirements.
*/

/* Problem Link
https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description/
*/

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1==0&&need2==0) return 0;
        long long ans=0;
        long long n1=need1, n2=need2, c1=cost1, c2=cost2, cB=costBoth;
        if(cB<(c1+c2)){
            long long both=min(n1, n2);
            ans+=both*cB;
            n1-=both;
            n2-=both;
        if(n2>0) ans+=n2*min(c2, cB);
        if(n1>0) ans+=n1*min(c1, cB);
            return ans;
        }
        return n1*c1+n2*c2;
    }
};