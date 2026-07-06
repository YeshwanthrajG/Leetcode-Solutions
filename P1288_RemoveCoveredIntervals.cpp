/* 
Problem ID : 1288 

Problem : Remove Covered Intervals

Statement : Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.
*/

/* Problem Link
https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int res=0, maxR=-1;
        for(auto &it:intervals){
            if(it[1]>maxR){
                res++;
                maxR=it[1];
            }
        }
        return res;
    }
};