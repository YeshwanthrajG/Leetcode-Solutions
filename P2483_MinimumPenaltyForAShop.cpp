/* 
Problem ID : 2483 

Problem : Minimum Penalty for a Shop

Statement : You are given the customer visit log of a shop represented by a 0-indexed string 
customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.
*/

/* Problem Link
https://leetcode.com/problems/minimum-penalty-for-a-shop/description/?envType=daily-question&envId=2025-12-26
*/

class Solution {
public:
    int bestClosingTime(string customers) {
        int bestTime=0, penalty=0, prefix=0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') prefix--;
            else prefix++;
            if(prefix<penalty){
                bestTime=i+1;
                penalty=prefix;
            }
        }
        return bestTime;
    }
};