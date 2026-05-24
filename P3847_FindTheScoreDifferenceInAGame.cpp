/* 
Problem ID : 3847 

Problem : Find the Score Difference in a Game

Statement : You are given an integer array nums, where nums[i] represents the points scored in the 
ith game.

There are exactly two players. Initially, the first player is active and the second player is inactive.

The following rules apply sequentially for each game i:

If nums[i] is odd, the active and inactive players swap roles.
In every 6th game (that is, game indices 5, 11, 17, ...), the active and inactive players swap roles.
The active player plays the ith game and gains nums[i] points.
Return the score difference, defined as the first player's total score minus the second player's total score.
*/

/* Problem Link
https://leetcode.com/problems/find-the-score-difference-in-a-game/description/
*/

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int score[2]={0,0};
        int n=nums.size();
        int active=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1) active^=1;
            if(i%6==5) active^=1;
            score[active]+=nums[i];
        }
        return score[0]-score[1];
    }
};