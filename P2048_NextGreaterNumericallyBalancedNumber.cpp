/* 
Problem ID : 2048 

Problem : Next Greater Numerically Balanced Number

Statement : An integer x is numerically balanced if for every digit d in the number x, there are exactly 
d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly greater than n.
*/

/* Problem Link
https://leetcode.com/problems/next-greater-numerically-balanced-number/description/
*/

class Solution {
public:
    void func(int n, vector<int> &cnt, vector<int> &list){
        if(n>0 && isBeautiful(cnt)) list.push_back(n);
        if(n>1224444) return;
        for(int i=1;i<=7;i++){
            if(cnt[i]<i){
                cnt[i]++;
                func(n*10+i, cnt, list);
                cnt[i]--;
            }
        }
    }

    bool isBeautiful(vector<int> &cnt){
        for(int i=1;i<=7;i++){
            if(cnt[i]!=0 && cnt[i]!=i) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        vector<int> list, cnt(10, 0);
        func(0, cnt, list);
        sort(list.begin(), list.end());
        for(int i:list) if(i>n) return i;
        return -1;
    }
};