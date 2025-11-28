/* 
Problem ID : 3751 

Problem : Total Waviness of Numbers in Range I

Statement : You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
*/

/* Problem Link
https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/
*/

class Solution {
public:
    int waveCount(int num){
        if(num<100) return 0;
        string s=to_string(num);
        int count=0;
        for(int i=1;i<s.size()-1;i++){
            int a=s[i-1]-'0';
            int b=s[i]-'0';
            int c=s[i+1]-'0';
            if(a<b && b>c) count++;
            else if(a>b && b<c) count++;
        }
        return count;
        
    }
    int totalWaviness(int num1, int num2) {
        int total=0;
        for(int i=num1;i<=num2;i++){
            total+=waveCount(i);
        }
        return total;
    }
};