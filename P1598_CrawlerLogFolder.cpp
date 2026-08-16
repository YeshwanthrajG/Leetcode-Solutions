/* 
Problem ID : 1598 

Problem : Crawler Log Folder

Statement : The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

"../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the 
same folder).
"./" : Remain in the same folder.
"x/" : Move to the child folder named x (This folder is guaranteed to always exist).
You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder after the change folder operations.
*/

/* Problem Link
https://leetcode.com/problems/crawler-log-folder/description/?envType=problem-list-v2&envId=n11ydiyj
*/


// 1st Approach
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(string s: logs){
            if(s!="../" && s!="./") st.push(s);
            else if(s=="../" && !st.empty()) st.pop();
        }
        int count=0;
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};


//2nd Approach
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(string s: logs){
            if(s!="../" && s!="./") count++;
            else if(s=="../") count=max(0, count-1);
        }
        return count;
    }
};