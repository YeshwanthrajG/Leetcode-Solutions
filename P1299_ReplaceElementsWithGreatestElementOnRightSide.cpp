/* 
Problem ID : 1299 

Problem : Replace Elements with Greatest Element on Right Side

Statement : Given an array arr, replace every element in that array with the greatest element among the 
elements to its right, and replace the last element with -1.

After doing so, return the array.
*/

/* Problem Link
https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxVal=-1;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            int temp=arr[i];
            arr[i]=maxVal;
            maxVal=max(maxVal, temp);
        }
        return arr;
    }
};