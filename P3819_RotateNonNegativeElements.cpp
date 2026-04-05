/* 
Problem ID : 3819 

Problem : Rotate Non Negative Elements

Statement : You are given an integer array nums and an integer k.

Rotate only the non-negative elements of the array to the left by k positions, in a cyclic manner.

All negative elements must stay in their original positions and must not move.

After rotation, place the non-negative elements back into the array in the new order, filling only the 
positions that originally contained non-negative values and skipping all negative positions.

Return the resulting array.
*/

/* Problem Link
https://leetcode.com/problems/rotate-non-negative-elements/description/
*/

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pos;
        for(int x :nums){
            if(x>=0) pos.push_back(x);
            
        }
        int m=pos.size();
        if(m==0) return nums;
        k%=m;
        vector<int> rot;
        for(int i=0;i<m;i++){
            rot.push_back(pos[(i+k)%m]);
            
        }
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i]=rot[idx++];
            }
        }
        return nums;
    }
};