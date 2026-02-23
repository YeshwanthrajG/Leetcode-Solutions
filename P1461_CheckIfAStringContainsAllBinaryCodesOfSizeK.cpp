/* 
Problem ID : 1461 

Problem : Check If a String Contains All Binary Codes of Size K

Statement : Given a binary string s and an integer k, return true if every 
binary code of length k is a substring of s. Otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/?envType=daily-question&envId=2026-02-23
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int req=1<<k;
        vector<bool> seen(req);
        int mask=req-1;
        int hash=0;
        for(int i=0;i<s.length();i++){
            hash=((hash<<1)&mask)|(s[i]&1);
            if(i>=k-1 && !seen[hash]){
                seen[hash]=true;
                req--;
                if(req==0) return true;
            }
        }
        return false;
    }
};