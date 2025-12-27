/* 
Problem ID : 3775 

Problem : Reverse Words With Same Vowel Count

Statement : You are given a string s consisting of lowercase English words, each separated by a 
single space.

Determine how many vowels appear in the first word. Then, reverse each following word that has the 
same vowel count. Leave all remaining words unchanged.

Return the resulting string.

Vowels are 'a', 'e', 'i', 'o', and 'u'.
*/

/* Problem Link
https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/
*/

class Solution {
public:
    int countVowels(const string& word){
        int count=0;
        for(char c:word){
            if(c=='a' || c=='e' ||c=='i' || c=='o' || c=='u') count++;
        }
        return count;
    }
    string reverseWords(string s) {
        vector<string> words;
        string temp;
        for(char c:s){
            if(c==' '){
                words.push_back(temp);
                temp.clear();
            }
            else {
                temp+=c;
            }
        }
        words.push_back(temp);
        int vowelCount=countVowels(words[0]);
        int n=words.size();
        for(int i=1;i<n;i++){
            if(countVowels(words[i])==vowelCount){
                reverse(words[i].begin(), words[i].end());
            }
        }
        string res;
        for(int i=0;i<n;i++){
            if(i>0) res+=' ';
            res+=words[i];
        }
        return res;
    }
};