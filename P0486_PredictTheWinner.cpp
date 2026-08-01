/* 
Problem ID : 486 

Problem : Predict the Winner

Statement : You are given an integer array nums. Two players are playing a game with this array: 
player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a 
score of 0. At each turn, the player takes one of the numbers from either end of the array 
(i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player 
adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is 
still the winner, and you should also return true. You may assume that both players are playing optimally.
*/

/* Problem Link
https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01
*/

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n%2==0) return true;
        vector<int> res(nums);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                res[j]=max(nums[i]-res[j], nums[j]-res[j-1]);
            }
        }
        return (res[n-1]>=0);
    }
};