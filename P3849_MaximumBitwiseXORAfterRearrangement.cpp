/* 
Problem ID : 3849 

Problem : Maximum Bitwise XOR After Rearrangement

Statement : You are given two binary strings s and t​​​​​​​, each of length n.

You may rearrange the characters of t in any order, but s must remain unchanged.

Return a binary string of length n representing the maximum integer value obtainable by taking the 
bitwise XOR of s and rearranged t.
*/

/* Problem Link
https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/description/
*/

class Solution {
public:
    string maximumXor(string s, string t) {
        int n=s.length();
        int count0=0, count1=0;
        for(char c:t){
            if(c=='0') count0++;
            else count1++;
        }
        string res;
        res.reserve(n);
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(count1>0){
                    res.push_back('1');
                    count1--;
                }
                else{
                    res.push_back('0');
                    count0--;
                }
            }
            else{
                if(count0>0){
                    res.push_back('1');
                    count0--;
                }
                else{
                    res.push_back('0');
                    count1--;
                }
            }
        }
        return res;
    }
};