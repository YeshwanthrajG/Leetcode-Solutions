/* 
Problem ID : 2129 

Problem : Capitalize the Title

Statement : You are given a string title consisting of one or more words separated by a single space, 
where each word consists of English letters. Capitalize the string by changing the capitalization of 
each word such that:

If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
Return the capitalized title.
*/

/* Problem Link
https://leetcode.com/problems/capitalize-the-title/description/
*/

class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> word;
        stringstream s(title);
        string temp;
        while(getline(s, temp, ' ')) word.push_back(temp);
        string res="";
        for(int i=0;i<word.size();i++){
            string s=word[i];
            int n=s.length();
            if(n<=2){
                for(int i=0;i<n;i++) s[i]=tolower(s[i]);
            }
            else{
                s[0]=toupper(s[0]);
                for(int i=1;i<n;i++) s[i]=tolower(s[i]);
            }
            if(i>0) res+=" ";
            res+=s;
        }
        return res;
    }
};