/* 
Problem ID : 67 

Problem : Add Binary

Statement : Given two binary strings a and b, return their sum as a binary string.
*/

/* Problem Link
https://leetcode.com/problems/add-binary/description/?envType=daily-question&envId=2026-02-15
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string s=(a.size()>=b.size())?a:b;
        int i=a.size()-1, j=b.size()-1;
        int k=s.size()-1;
        int C=0;
        while(k>=0){
            int A=i<0?0:a[i]&1;
            int B=j<0?0:b[j]&1;
            int S=(A^B)^C;
            int COUT=((A^B)&C)|(A&B);
            s[k]=S+'0';
            C=COUT;
            i--;
            j--;
            k--;
        }
        return C? (s.insert(s.begin(), '1'), s):s;
    }
};