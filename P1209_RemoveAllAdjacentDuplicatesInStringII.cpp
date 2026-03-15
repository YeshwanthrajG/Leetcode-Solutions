/* 
Problem ID : 1209 

Problem : Remove All Adjacent Duplicates in String II

Statement : You are given a string s and an integer k, a k duplicate removal consists of choosing k 
adjacent and equal letters from s and removing them, causing the left and the right side of the 
deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the 
answer is unique.
*/

/* Problem Link
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> st={{0, '#'}};
        for(char c:s){
            if(st.back().second!=c) st.push_back({1, c});
            else if(++st.back().first==k) st.pop_back();
        }
        string res;
        for(auto &p:st) res.append(p.first, p.second);
        return res;
    }
};