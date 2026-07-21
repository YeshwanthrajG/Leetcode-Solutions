/* 
Problem ID : 3499 

Problem : Maximize Active Section with Trade I

Statement : You are given a binary string s of length n, where:

'1' represents an active section.
'0' represents an inactive section.
You can perform at most one trade to maximize the number of active sections in s. 
In a trade, you:

Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
Return the maximum number of active sections in s after making the optimal trade.

Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1' + s + '1'. 
The augmented '1's do not contribute to the final count.
*/

/* Problem Link
https://leetcode.com/problems/maximize-active-section-with-trade-i/description/?envType=daily-question&envId=2026-07-21
*/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones=0;
        for(char c:s){
            if(c=='1') ones++;
        }
        string temp="1"+s+"1";
        vector<pair<char, int>> runs;
        for(char c:temp){
            if(runs.empty() || runs.back().first!=c) runs.push_back({c, 1});
            else runs.back().second++;
        }
        int res=0;
        for(int i=1;i+1<runs.size();i++){
            if(runs[i].first=='1' && runs[i-1].first=='0' && runs[i+1].first=='0'){
                res=max(res, (runs[i-1].second+runs[i+1].second));
            }
        }
        return ones+res;
    }
};