/* 
Problem ID : 2300 

Problem : Successful Pairs of Spells and Potions

Statement : You are given two positive integer arrays spells and potions, of length n and m respectively, 
where spells[i] represents the strength of the ith spell and potions[j] represents the strength of 
the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product 
of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a 
successful pair with the ith spell.
*/

/* Problem Link
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=daily-question&envId=2025-10-08
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int freq[100001]={0}, pMax=0;
        for(int p:potions){
            freq[p]++;
            pMax=max(pMax,p);
        }
        partial_sum(freq,freq+pMax+1, freq);
        const int n=spells.size(), m=potions.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            const int spell=spells[i];
            const long long k=(success+spell-1)/spell;
            if(k<=pMax){
                res[i]=m-(k>=1?freq[k-1]:0);
            }
        }
        return res;
    }
};