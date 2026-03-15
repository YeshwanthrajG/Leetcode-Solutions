/* 
Problem ID : 5 

Problem : Longest Palindromic Substring

Statement : Given a string s, return the longest palindromic substring in s.
*/

/* Problem Link
https://leetcode.com/problems/longest-palindromic-substring/description/
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        int maxL=1, st=0, end=0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            for(int j=0;j<i;j++){
                if(s[i]==s[j]&&(i-j<=2 || dp[j+1][i-1])){
                    dp[j][i]=true;
                    if(i-j+1>maxL){
                        maxL=i-j+1;
                        st=j;
                        end=i;
                    }
                }
            }
        }
        return s.substr(st, end-st+1);
    }
};