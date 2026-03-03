/* 
Problem ID : 682 

Problem : Baseball Game

Statement : You are keeping the scores for a baseball game with strange rules. 
At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation 
you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations 
fit in a 32-bit integer and that all operations are valid.
*/

/* Problem Link
https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> rec;
        for(string s:operations){
            if(s=="C") rec.pop_back();
            else if(s=="D"){
                int val=rec.back();
                rec.push_back(2*val);
            }
            else if(s=="+"){
                int n=rec.size();
                rec.push_back(rec[n-2]+rec[n-1]);
            }
            else{
                rec.push_back(stoi(s));
            }
        }
        int sum=0;
        for(auto &x:rec) sum+=x;
        return sum;
    }
};