/* 
Problem ID : 190 

Problem : Reverse Bits

Statement : Reverse bits of a given 32 bits signed integer.
*/

/* Problem Link
https://leetcode.com/problems/reverse-bits/description/?envType=daily-question&envId=2026-02-16
*/

class Solution {
public:
    int reverseBits(int n) {
        n=(n>>16) | (n<<16);
        n=((n&0b11111111000000001111111100000000)>>8) |
           ((n&0b00000000111111110000000011111111)<<8);
        n=((n&0b11110000111100001111000011110000)>>4) |
           ((n&0b00001111000011110000111100001111)<<4);
        n=((n&0b11001100110011001100110011001100)>>2) |
           ((n&0b00110011001100110011001100110011)<<2);
        n=((n&0b10101010101010101010101010101010)>>1) |
           ((n&0b01010101010101010101010101010101)<<1);
        return n;
    }
};