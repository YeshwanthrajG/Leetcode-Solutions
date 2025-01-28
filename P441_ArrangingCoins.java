/* 
Problem ID : 441 

Problem : Arranging Coins

Statement : You have n coins and you want to build a staircase with these coins. The staircase consists of k 
rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build
*/

/* Problem Link
https://leetcode.com/problems/arranging-coins/description/
*/

class Solution {
    public int arrangeCoins(int n) {
        int i=1;
        while(i<=n){
            n = n-i;
            i++;
        }
        return i-1;
    }
}
    // public int arrangeCoins(int n) {
    //     int temp=0;
    //     int i=0;
    //     do
    //     {
    //         temp+=++i;
    //     }
    //     while(temp<n);
       
    //     if(temp==n)
    //         return i;
           
    //     return i-1;
    // }
// }