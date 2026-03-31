/* 
Problem ID : 3790 

Problem : Smallest All-Ones Multiple

Statement : You are given a positive integer k.

Find the smallest integer n divisible by k that consists of only the digit 1 in its decimal representation 
(e.g., 1, 11, 111, ...).

Return an integer denoting the number of digits in the decimal representation of n. If no such n exists, 
return -1.
*/

/* Problem Link
https://leetcode.com/problems/smallest-all-ones-multiple/description/
*/

class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0) return -1;
        int rem=0;
        for(int l=1; l<=k;l++){
            rem=(rem*10+1)%k;
            if(rem==0){
                return l;
            }
        }
        return -1;
    }
};