/* 
Problem ID : 3776 

Problem : Minimum Moves to Balance Circular Array

Statement : You are given a circular array balance of length n, where balance[i] is the net 
balance of person i.

In one move, a person can transfer exactly 1 unit of balance to either their left or right neighbor.

Return the minimum number of moves required so that every person has a non-negative balance. 
If it is impossible, return -1.

Note: You are guaranteed that at most 1 index has a negative balance initially.
*/

/* Problem Link
https://leetcode.com/problems/minimum-moves-to-balance-circular-array/description/
*/

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n=balance.size();
        long long total=0;
        int neg=-1;
        for(int i=0;i<n;i++){
            total+=balance[i];
            if(balance[i]<0) {
                neg=i;
            }
        }
        if(neg==-1) return 0;
        if(total<0) return -1;
        long long temp=-balance[neg];
        long long moves=0;
        int left=(neg-1+n)%n;
        int right=(neg+1)%n;
        int dist=1;
        while(temp>0 && (left!=neg || right!=neg)){
            if(balance[left]>0){
                long long take=min((long long)balance[left], temp);
                moves+=take*dist;
                temp-=take;
                balance[left]-=take;
            }
            if(temp>0 && balance[right]>0){
                long long take=min((long long)balance[right], temp);
                moves+=take*dist;
                temp-=take;
                balance[right]-=take;
            }
            left=(left-1+n)%n;
            right=(right+1)%n;
            dist++;
        }
        return temp==0?moves:-1;
    }
};