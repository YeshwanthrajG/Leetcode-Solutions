/* 
Problem ID : 1927 

Problem : Sum Game

Statement : Alice and Bob take turns playing a game, with Alice starting first.

You are given a string num of even length consisting of digits and '?' characters. On each turn, 
a player will do the following if there is still at least one '?' in num:

Choose an index i where num[i] == '?'.
Replace num[i] with any digit between '0' and '9'.
The game ends when there are no more '?' characters in num.

For Bob to win, the sum of the digits in the first half of num must be equal to the sum of the digits 
in the second half. For Alice to win, the sums must not be equal.

For example, if the game ended with num = "243801", then Bob wins because 2+4+3 = 8+0+1. If the game 
ended with num = "243803", then Alice wins because 2+4+3 != 8+0+3.
Assuming Alice and Bob play optimally, return true if Alice will win and false if Bob will win.
*/

/* Problem Link
https://leetcode.com/problems/sum-game/description/?envType=daily-question&envId=2026-08-23
*/

class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        vector<int> sum(2, 0), temp(2, 0);
        for(int i=0;i<n;i++){
            int x=i/(n>>1);
            if(num[i]=='?') temp[x]++;
            else sum[x]+=num[i]-'0';
        }
        return ((temp[0]+temp[1] & 1) || ((sum[0]-sum[1])<<1) != (temp[1]-temp[0])*9);
    }
};