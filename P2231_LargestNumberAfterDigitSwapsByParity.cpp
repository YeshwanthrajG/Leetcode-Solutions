/* 
Problem ID : 2231 

Problem : Largest Number After Digit Swaps by Parity

Statement : You are given a positive integer num. You may swap any two digits of num that have the same 
parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.
*/

/* Problem Link
https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/
*/

class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        vector<int> odd, even;
        int temp=num;
        while(temp>0){
            int x=temp%10;
            if(x%2==0) even.push_back(x);
            else odd.push_back(x);
            temp/=10;
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        int i=0, j=0;
        for(char &c:s){
            if((c-'0')%2==0) {
                c=(even.back())+'0';
                even.pop_back();
            }
            else{
                c=(odd.back())+'0';
                odd.pop_back();
            }
        }
        return stoi(s);
    }
};