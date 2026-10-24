/* 
Problem ID : 2409 

Problem : Count Days Spent Together

Statement : Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city 
from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates 
arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", 
corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the 
number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].
*/

/* Problem Link
https://leetcode.com/problems/count-days-spent-together/description/?envType=daily-question&envId=2026-10-24
*/

class Solution {
public:
    int func(string s){
        int a=(s[0]-'0')*10+(s[1]-'0');
        int b=(s[3]-'0')*10+(s[4]-'0');
        return (275*a)/9-2*((a+9)/12)+b-30;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        return (max(0, min(func(leaveAlice), func(leaveBob))-max(func(arriveAlice), func(arriveBob))+1));
    }
};