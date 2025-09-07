/* 
Problem ID : 1304 

Problem : Find N Unique Integers Sum up to Zero

Statement : Given an integer n, return any array containing n unique integers such that they add up to 0.
*/

/* Problem Link
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?envType=daily-question&envId=2025-09-07
*/

class Solution {
    public int[] sumZero(int n) {
        int half=n/2;
        int res[]=new int[n];
        int k=0;
        // for(int i=-half;i<0;i++){
        //     res[k++]=i;
        // }
        for(int i=1;i<=half;i++){
            res[k++]=i;
            res[k++]=-i;
        }
        if(n%2==1)  res[k++]=0;
        return res;
    }
}