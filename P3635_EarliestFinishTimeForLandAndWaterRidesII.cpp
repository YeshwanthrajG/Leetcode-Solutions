/* 
Problem ID : 3635 

Problem : Earliest Finish Time for Land and Water Rides II

Statement : You are given two categories of theme park attractions: land rides and water rides.

Land rides
    landStartTime[i] – the earliest time the ith land ride can be boarded.
    landDuration[i] – how long the ith land ride lasts.

Water rides
    waterStartTime[j] – the earliest time the jth water ride can be boarded.
    waterDuration[j] – how long the jth water ride lasts.

A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait 
until it opens.
Return the earliest possible time at which the tourist can finish both rides.
*/

/* Problem Link
https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/?envType=daily-question&envId=2026-06-03
*/

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l=INT_MAX, w=INT_MAX, minL=INT_MAX, minW=INT_MAX;
        int m=landStartTime.size(), n=waterStartTime.size();
        for(int i=0;i<m;i++) l=min(l, landStartTime[i]+landDuration[i]);
        for(int i=0;i<n;i++){
            w=min(w, waterStartTime[i]+waterDuration[i]);
            minL=min(minL, max(waterStartTime[i], l)+waterDuration[i]);
        }
        for(int i=0;i<m;i++){
            minW=min(minW, max(landStartTime[i], w)+landDuration[i]);
        }
        return min(minL, minW);
    }
};