/* 
Problem ID : 3633 

Problem : Earliest Finish Time for Land and Water Rides I

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
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides.
*/

/* Problem Link
https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/
*/

class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int minFinishTime=Integer.MAX_VALUE;
        for(int i=0;i<landStartTime.length;i++){
            for(int j=0;j<waterStartTime.length;j++){
                int finishLand=landStartTime[i]+landDuration[i];
                int startWater=Math.max(finishLand,waterStartTime[j]);
                int finishWater=startWater+waterDuration[j];
                minFinishTime=Math.min(minFinishTime,finishWater);

                // int startWater=Math.max(finishLand,)
                finishWater=waterStartTime[j]+waterDuration[j];
                startWater=Math.max(finishWater,landStartTime[i]);
                finishLand=startWater+landDuration[i];
                minFinishTime=Math.min(minFinishTime,finishLand);
                
            }
        }
        return minFinishTime;
    }
}