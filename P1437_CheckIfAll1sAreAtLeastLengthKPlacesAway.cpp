/* 
Problem ID : 1437 

Problem : Check If All 1's Are at Least Length K Places Away

Statement : Given an binary array nums and an integer k, return 
true if all 1's are at least k places away from each other, otherwise return false.
*/

/* Problem Link
https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int zIdx=0;
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(flag && nums[i]){
                flag=false;
                zIdx=i;
                continue;
            }
            if(nums[i]){
                if(i-zIdx-1>=k) zIdx=i;
                else return false;
            }
        }
        return true;
    }
};