/* 
Problem ID : 3360 

Problem : Stone Removal Game

Statement : Alice and Bob are playing a game where they take turns removing stones from a pile, 
with Alice going first.

Alice starts by removing exactly 10 stones on her first turn.
For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent.
The player who cannot make a move loses the game.

Given a positive integer n, return true if Alice wins the game and false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/stone-removal-game/description/?envType=daily-question&envId=2026-11-26
*/

class Solution {
public:
    bool canAliceWin(int n) {
        int a=10, b=0;
        while(n>=a){
            n-=a;
            a--;
            b++;
        }
        return (a%2==1);
    }
};