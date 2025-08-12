/* 
Problem ID : 20 

Problem : Valid Parentheses

Statement : Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input 
string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

/* Problem Link
https://leetcode.com/problems/valid-parentheses/description/
*/

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st=new Stack<>();
        for(char c:s.toCharArray()){
            if(c=='('||c=='{'||c=='[')  st.push(c);
            else if(c==')' && !st.isEmpty() && st.peek()=='(') st.pop();
            else if(c=='}' && !st.isEmpty() && st.peek()=='{') st.pop();
            else if(c==']' && !st.isEmpty() && st.peek()=='[') st.pop();
            else return false;
        }
        if(!st.isEmpty())   return false;
        return true;
    }
}