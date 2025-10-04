/* 
Problem ID : 11 

Problem : Container With Most Water

Statement : You are given an integer array height of length n. There are n vertical lines drawn 
such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains 
the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

/* Problem Link
https://leetcode.com/problems/container-with-most-water/description/?envType=daily-question&envId=2025-10-04
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxVal=0;
        while(left<right){
            int temp=(right-left)*(min(height[left],height[right]));
            maxVal=max(maxVal,temp);
            if(height[left]<height[right])  left++;
            else right--;
        }
        return maxVal;
    }
};