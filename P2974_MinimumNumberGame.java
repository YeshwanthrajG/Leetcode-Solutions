/* 
Problem ID : 2974 

Problem : Minimum Number Game

Statement : You are given a 0-indexed integer array nums of even length and there is also an empty array arr. 
Alice and Bob decided to play a game where in every round Alice and Bob will do one move. The rules of the game 
are as follows:

Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
Now, first Bob will append the removed element in the array arr, and then Alice does the same.
The game continues until nums becomes empty.
Return the resulting array arr.
*/

/* Problem Link
https://leetcode.com/problems/minimum-number-game/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
    public int[] numberGame(int[] nums) {
        Arrays.sort(nums);
        int i=0;
        while(i<nums.length-1){
            int temp=nums[i+1];
            nums[i+1]=nums[i];
            nums[i]=temp;
            i+=2;
        }
        return nums;
    }
}