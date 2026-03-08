/* 
Problem ID : 1980 

Problem : Find Unique Binary String

Statement : Given an array of strings nums containing n unique binary strings each of length n, 
return a binary string of length n that does not appear in nums. If there are multiple answers, 
you may return any of them.
*/

/* Problem Link
https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int size=pow(2,n);
        vector<int> num(size, 0);
        for(string s:nums){
            int i=stoi(s, nullptr, 2);
            num[i]++;
        }
        for(int i=0;i<size;i++){
            if(num[i]==0){
                string res=bitset<32>(i).to_string();
                res=res.substr(32-n);
                return res;
            }
        }
        return string(n, '0');
    }
};