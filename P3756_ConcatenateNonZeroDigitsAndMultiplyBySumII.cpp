/* 
Problem ID : 3756 

Problem : Concatenate Non-Zero Digits and Multiply by Sum II

Statement : You are given a string s of length m consisting of digits. You are also given a 2D integer 
array queries, where queries[i] = [li, ri].

For each queries[i], extract the substring s[li..ri]. Then, perform the following:

Form a new integer x by concatenating all the non-zero digits from the substring in their original order. 
If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7.
*/

/* Problem Link
https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/?envType=daily-question&envId=2026-07-08
*/

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length(), m=queries.size();
        long long MOD=1e9+7;
        vector<long long> prefSum(n+1, 0), pVal(n+1, 0), pCnt(n+1, 0);
        vector<long long> power(n+1, 1);
        for(int i=1;i<=n;i++){
            power[i]=(power[i-1]*10)%MOD;
        }
        for(int i=0;i<n;i++){
            int dig=s[i]-'0';
            prefSum[i+1]=prefSum[i]+dig;
            pCnt[i+1]=pCnt[i]+(dig!=0);
            if(dig==0) pVal[i+1]=pVal[i];
            else pVal[i+1]=(pVal[i]*10+dig)%MOD;
        }
        vector<int> res(m);
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int len=pCnt[r+1]-pCnt[l];
            long long st=pVal[l], end=pVal[r+1];
            long long temp=(end-(st*power[len])%MOD+MOD)%MOD;
            long long sum=prefSum[r+1]-prefSum[l];
            res[i]=(temp*sum)%MOD;
        }
        return res;
    }
};