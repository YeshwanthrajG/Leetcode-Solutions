/* 
Problem ID : 1404 

Problem : Number of Steps to Reduce a Number in Binary Representation to One

Statement : Given the binary representation of an integer as a string s, return the number of 
steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
*/

/* Problem Link
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26
*/

class Solution {
public:
    int numSteps(string s) {
        int steps=0, carry=0;
        for(int i=s.length()-1;i>0;i--){
            if((s[i]=='1') + carry==1){
                steps+=2;
                carry=1;
            }
            else steps++;
        }
        return steps+carry;
    }
};