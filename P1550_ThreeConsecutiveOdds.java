/* 
Problem ID : 1550 

Problem : Three Consecutive Odds

Statement : Given an integer array arr, 
return true if there are three consecutive odd numbers in the array. Otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2025-05-11
*/

class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int n=arr.length;
        if(n==1||n==2)  return false;
        if(n==3)
        {
            if(arr[0]%2==1&&arr[1]%2==1&&arr[2]%2==1)
                return true;
        }
        for(int i=0;i<=n-3;i++)
        {
            if(arr[i]%2==1&&arr[i+1]%2==1&&arr[i+2]%2==1)
                return true;
        }
        return false;
    }
}