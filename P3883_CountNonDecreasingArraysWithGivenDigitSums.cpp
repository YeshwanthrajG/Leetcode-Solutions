/* 
Problem ID : 3883 

Problem : Count Non Decreasing Arrays With Given Digit Sums

Statement : You are given an integer array digitSum of length n.

An array arr of length n is considered valid if:

0 <= arr[i] <= 5000
it is non-decreasing.
the sum of the digits of arr[i] equals digitSum[i].
Return an integer denoting the number of distinct valid arrays. Since the answer may be large, return it modulo 109 + 7.

An array is said to be non-decreasing if each element is greater than or equal to the previous element, if it exists.
*/

/* Problem Link
https://leetcode.com/problems/count-non-decreasing-arrays-with-given-digit-sums/description/
*/

class Solution {
public:
    static const int MOD=1e9+7;

    int findDigitSum(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    
    int countArrays(vector<int>& digitSum) {
        int n=digitSum.size();
        vector<vector<int>> range(51);
        for(int i=0;i<=5000;i++){
            int sum=findDigitSum(i);
            if(sum<=50)    range[sum].push_back(i);
        }
        for(int i=0;i<n;i++) if(range[digitSum[i]].empty()) return 0;
        vector<long long> dp(5001, 0);
        for(int i:range[digitSum[0]]) dp[i]=1;
        for(int i=1;i<n;i++){
            vector<long long> prefix(5001, 0);
            prefix[0]=dp[0];
            for(int j=1;j<=5000;j++){
                prefix[j]=(prefix[j-1]+dp[j])%MOD;
            }
            vector<long long> ndp(5001, 0);
            for(int j:range[digitSum[i]]){
                ndp[j]=prefix[j];
            }
            dp=ndp;
        }
        long long res=0;
        for(int i=0;i<=5000;i++){
            res=(res+dp[i])%MOD;
        }
        return res;
    }
};