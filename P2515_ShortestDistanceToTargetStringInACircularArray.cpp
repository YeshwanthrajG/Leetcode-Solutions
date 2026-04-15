/* 
Problem ID : 2515 

Problem : Shortest Distance to Target String in a Circular Array

Statement : You are given a 0-indexed circular string array words and a string target. A circular array 
means that the array's end connects to the array's beginning.

Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is 
words[(i - 1 + n) % n], where n is the length of words.
Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

Return the shortest distance needed to reach the string target. If the string target does not exist in 
words, return -1.
*/

/* Problem Link
https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15
*/

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        for(int i=0;i<=n>>1;i++){
            if((words[(startIndex+i)%n]==target) | (words[(startIndex+n-i)%n]==target)) return i;
        }
        return -1;
    }
};