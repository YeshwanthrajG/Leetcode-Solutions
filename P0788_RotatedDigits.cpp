/* 
Problem ID : 788 

Problem : Rotated Digits

Statement : An integer x is a good if after rotating each digit individually by 180 degrees, we get a 
valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 
2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].
*/

/* Problem Link
https://leetcode.com/problems/rotated-digits/description/?envType=daily-question&envId=2026-05-02
*/

class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n+1, 0);
        int cnt=0;
        for(int i=0;i<=n;i++){
            if(i<10){
                if(i==0 || i==1 || i==8) dp[i]=1;
                else if(i==2 || i==5 || i==6 || i==9){
                    dp[i]=2;
                    cnt++;
                }
                else dp[i]=0;
            }
            else {
                int x=dp[i/10];
                int y=dp[i%10];
                if(x==1 && y==1) dp[i]=1;
                else if(x>=1 && y>=1){
                    dp[i]=2;
                    cnt++;
                }
                else dp[i]=0;
            }
        }
        return cnt;
    }
};