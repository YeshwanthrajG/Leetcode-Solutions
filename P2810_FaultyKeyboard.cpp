/* 
Problem ID : 2810 

Problem : Faulty Keyboard

Statement : Your laptop keyboard is faulty, and whenever you type a character 'i' on it, it reverses 
the string that you have written. Typing other characters works as expected.

You are given a 0-indexed string s, and you type each character of s using your faulty keyboard.

Return the final string that will be present on your laptop screen.
*/

/* Problem Link
https://leetcode.com/problems/faulty-keyboard/description/?envType=problem-list-v2&envId=n11ydiyj
*/

class Solution {
public:
    string finalString(string s) {
        int n=s.length();
        string res;
        for(int i=0;i<n;i++){
            if(s[i]=='i'){
                if(i+1<n && s[i+1]=='i') i++;
                else reverse(res.begin(), res.end());
            }
            else res.push_back(s[i]);
        }
        return res;
    }
};