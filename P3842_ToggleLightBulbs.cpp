/* 
Problem ID : 3842 

Problem : Toggle Light Bulbs

Statement : You are given an array bulbs of integers between 1 and 100.

There are 100 light bulbs numbered from 1 to 100. All of them are switched off initially.

For each element bulbs[i] in the array bulbs:

If the bulbs[i]th light bulb is currently off, switch it on.
Otherwise, switch it off.
Return the list of integers denoting the light bulbs that are on in the end, sorted in ascending order. 
If no bulb is on, return an empty list.
*/

/* Problem Link
https://leetcode.com/problems/toggle-light-bulbs/description/
*/

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> toggle(101,false);
        int n=bulbs.size();
        for(int b:bulbs){
            toggle[b]=!toggle[b];
        }
        vector<int> res;
        for(int i=1;i<=100;i++){
            if(toggle[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};