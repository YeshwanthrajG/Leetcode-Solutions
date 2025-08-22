/* 
Problem ID : 3232 

Problem : Find if Digit Game Can Be Won

Statement : You are given an array of positive integers nums.

Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers or all double-digit 
numbers from nums, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is strictly 
greater than the sum of Bob's numbers.

Return true if Alice can win this game, otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/find-if-digit-game-can-be-won/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
    public boolean canAliceWin(int[] nums) {
        int singleDigit=0;
        int moreDigit=0;
        for(int i:nums){
            if(i>9)  moreDigit+=i;
            else    singleDigit+=i;
        }
        return singleDigit!=moreDigit;
    }
}