/* 
Problem ID : 485 

Problem : Max Consecutive Ones

Statement : Given a binary array nums, return the maximum number of consecutive 1's in the array.

*/

/* Problem Link
https://leetcode.com/problems/max-consecutive-ones/description/
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt=0, cnt=0;
        for(int i:nums){
            if(i) cnt++;
            else{
                maxCnt=max(maxCnt, cnt);
                cnt=0;
            }
        }
        return max(maxCnt, cnt);
    }
};