/* 
Problem ID : 868 

Problem : Binary Gap

Statement : Given a positive integer n, find and return the longest distance between any two 
adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.

Two 1's are adjacent if there are only 0's separating them (possibly no 0's). 
The distance between two 1's is the absolute difference between their bit positions. For example, 
the two 1's in "1001" have a distance of 3.
*/

/* Problem Link
https://leetcode.com/problems/binary-gap/description/?envType=daily-question&envId=2026-02-22
*/

class Solution {
public:
    int binaryGap(int n) {
        while(!(n&1)) n>>=1;
        int gap=0, maxGap=0;
        if(n==1) return 0;
        while(n){
            if(n&1){
                maxGap=max(maxGap, gap);
                gap=0;
            }
            else gap++;
            n>>=1;
        }   
        return maxGap+1;
    }
};