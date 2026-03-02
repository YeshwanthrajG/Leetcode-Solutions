/* 
Problem ID : 1822 

Problem : Sign of the Product of an Array

Statement : Implement a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).
*/

/* Problem Link
https://leetcode.com/problems/sign-of-the-product-of-an-array/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int signFunc(int x){
        if(x>0) return 1;
        if(x==0) return 0;
        return -1;
    }

    int arraySign(vector<int>& nums) {
        int res=1;
        for(auto &x:nums){
            res*=signFunc(x);
            if(res==0) break;
        }
        return res;
    }
};