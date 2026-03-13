/* 
Problem ID : 3296 

Problem : Minimum Number of Seconds to Make Mountain Height Zero

Statement : You are given an integer mountainHeight denoting the height of a mountain.

You are also given an integer array workerTimes representing the work time of workers in seconds.

The workers work simultaneously to reduce the height of the mountain. For worker i:

To decrease the mountain's height by x, it takes workerTimes[i] + workerTimes[i] * 2 + ... + 
workerTimes[i] * x seconds. For example:
To reduce the height of the mountain by 1, it takes workerTimes[i] seconds.
To reduce the height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2 seconds, 
and so on.
Return an integer representing the minimum number of seconds required for the workers to make the 
height of the mountain 0.
*/

/* Problem Link
https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/?envType=daily-question&envId=2026-03-13
*/

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low=1, high=1e16;
        int n=workerTimes.size();
        while(low<high){
            long long mid=(low+(high-low)/2);
            long long total=0;
            for(int i=0;i<n && total<mountainHeight;i++){
                total+=(long long)(sqrt((double)mid/workerTimes[i]*2+0.25)-0.5);
            }
            if(total>=mountainHeight) high=mid;
            else low=mid+1;
        }
        return low;
    }
};