/* 
Problem ID : 3771 

Problem : Total Score of Dungeon Runs

Statement : You are given a positive integer hp and two positive 1-indexed integer arrays damage and 
requirement.

There is a dungeon with n trap rooms numbered from 1 to n. Entering room i reduces your health points 
by damage[i]. After that reduction, if your remaining health points are at least requirement[i], 
you earn 1 point for that room.

Let score(j) be the number of points you get if you start with hp health points and enter the 
rooms j, j + 1, ..., n in this order.

Return the integer score(1) + score(2) + ... + score(n), the sum of scores over all starting rooms.

Note: You cannot skip rooms. You can finish your journey even if your health points become non-positive.
*/

/* Problem Link
https://leetcode.com/problems/total-score-of-dungeon-runs/description/
*/

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n=damage.size();
        vector<long long> prefix(n+1, 0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+damage[i-1];
        }
        long long total=0;
        for(int i=1;i<=n;i++){
            long long need=requirement[i-1] + prefix[i] - hp;
            int pos=lower_bound(prefix.begin(), prefix.end(), need)-prefix.begin();
            if(pos<=i-1){
                total+=(i-pos);
            }
        }
        return total;
    }
};