/* 
Problem ID : 3769 

Problem : Sort Integers by Binary Reflection

Statement : You are given an integer array nums.

The binary reflection of a positive integer is defined as the number obtained by reversing the order of 
its binary digits (ignoring any leading zeros) and interpreting the resulting binary number as a decimal.

Sort the array in ascending order based on the binary reflection of each element. If two different 
numbers have the same binary reflection, the smaller original number should appear first.

Return the resulting sorted array.
*/

/* Problem Link
https://leetcode.com/problems/sort-integers-by-binary-reflection/
*/

class Solution {
public:
    int binary(int x){
        string b;
        while(x>0){
            b.push_back('0' + (x&1));
            x>>=1;
        }
        int val=0;
        for(char c:b){
            val=val*2+(c-'0');
        }
        return val;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for(int x:nums){
            arr.push_back({binary(x),x});
        }
        sort(arr.begin(), arr.end(), [](auto& a, auto& b){
            if(a.first!=b.first) return a.first<b.first;
            return a.second<b.second;
        });
        vector<int> res;
        for(auto& x:arr){
            res.push_back(x.second);
        }
        return res;
    }
};