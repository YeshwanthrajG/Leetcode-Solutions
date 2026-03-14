/* 
Problem ID : 1415 

Problem : The k-th Lexicographical String of All Happy Strings of Length n

Statement : A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", 
"baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in 
lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings 
of length n.
*/

/* Problem Link
https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14
*/

class Solution {
public:
    string getHappyString(int n, int k) {
        int sz=pow(2, n-1);
        if(3*sz<k) return "";
        string res="";
        if(k<=sz)    res+='a';
        else if(k<=2*sz){
            res+='b';
            k-=sz;
        }
        else{
            res+='c';
            k-=2*sz;
        }
        string op[]={"bc", "ac", "ab"};
        for(int i=1;i<n;i++){
            sz/=2;
            string &ch=op[res.back()-'a'];
            if(k<=sz) res+=ch[0];
            else{
                res+=ch[1];
                k-=sz;
            }
        }
        return res;
    }
};