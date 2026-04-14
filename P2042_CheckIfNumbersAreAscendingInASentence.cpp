/* 
Problem ID : 2042 

Problem : Check if Numbers Are Ascending in a Sentence

Statement : A sentence is a list of tokens separated by a single space with no leading or trailing spaces. 
Every token is either a positive number consisting of digits 0-9 with no leading zeros, or a word consisting of 
lowercase English letters.

For example, "a puppy has 2 eyes 4 legs" is a sentence with seven tokens: "2" and "4" are numbers and the other 
tokens such as "puppy" are words.
Given a string s representing a sentence, you need to check if all the numbers in s are strictly increasing from 
left to right (i.e., other than the last number, each number is strictly smaller than the number on its right in s).

Return true if so, or false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/description/?envType=problem-list-v2&envId=n11ydiyj
*/

class Solution {
public:
    bool areNumbersAscending(string s) {
        char last='0';
        int curr=0, prev=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(isdigit(c)){
                curr=curr*10+(c-'0');
            }
            else if(curr!=0){
                if(prev>=curr) return false;
                prev=curr;
                curr=0;
            }
        }
        return curr==0 || prev<curr;
    }
};