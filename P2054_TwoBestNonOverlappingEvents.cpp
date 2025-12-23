/* 
Problem ID : 2054 

Problem : Two Best Non-Overlapping Events

Statement : You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. 
The ith event starts at startTimei and ends at endTimei, and if you attend this event, 
you will receive a value of valuei. You can choose at most two non-overlapping events to attend such 
that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where 
one of them starts and the other ends at the same time. More specifically, if you attend an event 
with end time t, the next event must start at or after t + 1.
*/

/* Problem Link
https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2025-12-23
*/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int  n=events.size();
        vector<int> maxSuffix(n);
        sort(events.begin(), events.end());
        maxSuffix[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            maxSuffix[i]=max(maxSuffix[i+1], events[i][2]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int currValue=events[i][2];
            ans=max(ans, currValue);
            int next=events[i][1]+1;
            int low=i+1, high=n-1, idx=-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(events[mid][0]>=next){
                    idx=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            if(idx!=-1) ans=max(ans, currValue+maxSuffix[idx]);
        }
        return ans;
    }
};