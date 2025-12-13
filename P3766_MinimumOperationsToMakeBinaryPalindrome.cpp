/* 
Problem ID : 3766 

Problem : Minimum Operations to Make Binary Palindrome

Statement : You are given an integer array nums.

For each element nums[i], you may perform the following operations any number of times (including zero):

Increase nums[i] by 1, or
Decrease nums[i] by 1.
A number is called a binary palindrome if its binary representation without leading zeros reads the 
same forward and backward.

Your task is to return an integer array ans, where ans[i] represents the minimum number of operations 
required to convert nums[i] into a binary palindrome.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-make-binary-palindrome/description/
*/

class Solution {
public:
    bool isBinPali(int x){
        string b;
        while(x>0){
            b.push_back((x&1)+'0');
            x>>=1;
        }
        int l=0,r=b.size()-1;
        while(l<r){
            if(b[l]!=b[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int x=nums[i];
            int d=0;
            while(true){
                int a=x-d;
                int b=x+d;
                if(a>=1 && isBinPali(a)){
                    res[i]=d;
                    break;
                }
                if(isBinPali(b)){
                    res[i]=d;
                    break;
                }
                d++;
            }
        }
        return res;
    }
};