/* 
Problem ID : 135 

Problem : There are n children standing in a line. Each child is assigned a rating value 
given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Statement : Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

/* Problem Link
https://leetcode.com/problems/candy/description/
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();
       vector<int> res(n,1);
       for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]) res[i]=res[i-1]+1;
       } 
       for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]) res[i]=max(res[i], res[i+1]+1);
       }
       int total=0;
       for(int x:res) total+=x;
       return total;
    }
};