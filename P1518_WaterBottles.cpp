/* 
Problem ID : 1518 

Problem : Water Bottles

Statement : There are numBottles water bottles that are initially full of water. 
You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can 
drink.
*/

/* Problem Link
https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2025-10-01
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+(numBottles-1)/(numExchange-1);
    }
};