/* 
Problem ID : 1957 

Problem : Delete Characters to Make Fancy String

Statement : A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.
*/

/* Problem Link
https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2025-07-21
*/

class Solution {
    public String makeFancyString(String s) {
        StringBuilder res=new StringBuilder();
        for(char c:s.toCharArray()){
            int len=res.length();
            if(len>=2&&res.charAt(len-1)==c&&res.charAt(len-2)==c){
                continue;
            }
            res.append(c);
        }
        return res.toString();
    }
}