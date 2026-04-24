/* 
Problem ID : 2833 

Problem : Furthest Point From Origin

Statement : You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. 
The string represents your movement on a number line starting from the origin 0.

In the ith move, you can choose one of the following directions:

move to the left if moves[i] = 'L' or moves[i] = '_'
move to the right if moves[i] = 'R' or moves[i] = '_'
Return the distance from the origin of the furthest point you can get to after n moves.
*/

/* Problem Link
https://leetcode.com/problems/furthest-point-from-origin/description/?envType=daily-question&envId=2026-04-24
*/

class Solution {
public:
    int findDistance(string moves, char place){
        int i=0;
        for(char c:moves){
            if(c=='L') i++;
            else if(c=='_' && place=='L') i++;
            else if(c=='_' && place=='R') i--;
            else i--;
        }
        return abs(i);
    }

    int furthestDistanceFromOrigin(string moves) {
        int x=0, y=0;
        return max(findDistance(moves, 'L'), findDistance(moves, 'R'));

    }
};