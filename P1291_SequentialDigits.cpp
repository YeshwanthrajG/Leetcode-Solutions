/* 
Problem ID : 1291 

Problem : Sequential Digits

Statement : An integer has sequential digits if and only if each digit in the number is one more than 
the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
*/

/* Problem Link
https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2026-07-13
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num="123456789";
        string l=to_string(low), h=to_string(high);
        int a=l.length(), b=h.length();
        vector<int> res;
        for(int i=a;i<=b;i++){
            for(int j=0;j<=9-i;j++){
                string temp=num.substr(j, i);
                int n=stoi(temp);
                if(n>=low && n<=high) res.push_back(n);
            }
        }
        return res;
    }
};