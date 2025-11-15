/* 
Problem ID : 2108 

Problem : Find First Palindromic String in the Array

Statement : Given an array of strings words, return the first palindromic string in the array. 
If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
*/

/* Problem Link
https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    bool isPalindrome(string word){
        int n=word.size();
        for(int i=0;i<(int)n/2;i++){
            if(word[i]!=word[n-i-1])    return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto& a:words){
            if(isPalindrome(a))  return a;
        }
        return "";
    }
};