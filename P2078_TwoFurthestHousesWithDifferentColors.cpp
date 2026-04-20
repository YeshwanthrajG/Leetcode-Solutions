/* 
Problem ID : 2078 

Problem : Two Furthest Houses With Different Colors

Statement : There are n houses evenly lined up on the street, and each house is beautifully painted. 
You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the 
ith house.

Return the maximum distance between two houses with different colors.

The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.
*/

/* Problem Link
https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/?envType=daily-question&envId=2026-04-20
*/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int l=0, r=n-1;
        int maxVal=0;
        while(l<r){
            if(colors[l]!=colors[r]){
                maxVal=max(maxVal, (r-l));
                break;
            }
            r--;
        }
        l=0, r=n-1;
        while(l<r){
            if(colors[l]!=colors[r]){
                maxVal=max(maxVal, (r-l));
                break;
            }
            l++;
        }
        return maxVal;
    }
};