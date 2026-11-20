/* 
Problem ID : 3861 

Problem : Minimum Capacity Box

Statement : You are given an integer array capacity, where capacity[i] represents the capacity of the 
ith box, and an integer itemSize representing the size of an item.

The ith box can store the item if capacity[i] >= itemSize.

Return an integer denoting the index of the box with the minimum capacity that can store the item. 
If multiple such boxes exist, return the smallest index.

If no box can store the item, return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-capacity-box/description/
*/

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minC=INT_MAX;
        int idx=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize && capacity[i]<minC){
                minC=capacity[i];
                idx=i;
            }
        }
        return idx;
    }
};