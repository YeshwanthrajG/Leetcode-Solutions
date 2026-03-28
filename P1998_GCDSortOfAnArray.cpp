/* 
Problem ID : 1998 

Problem : GCD Sort of an Array

Statement : You are given an integer array nums, and you can perform the following operation any 
number of times on nums:

Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], 
nums[j]) is the greatest common divisor of nums[i] and nums[j].
Return true if it is possible to sort nums in non-decreasing order using the above swap method, or 
false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/gcd-sort-of-an-array/description/
*/

class Solution {
public:
    class DisjointSet{
        public:
        vector<int> p;
        DisjointSet(int n){
            p.resize(n, -1);
        }
        int findNode(int node){
            if(p[node]<0) return node;
            return p[node]=findNode(p[node]);
        }
        void uniteNodes(int x, int y){
            int pX=findNode(x);
            int pY=findNode(y);
            if(pX==pY) return;
            if(abs(p[pX])>abs(p[pY])){
                p[pX]+=p[pY];
                p[pY]=pX;
            }
            else{
                p[pY]+=p[pX];
                p[pX]=pY;
            }
        }
    };

    bool gcdSort(vector<int>& nums) {
        DisjointSet d(100001);
        int n=nums.size();
        for(int x:nums){
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    d.uniteNodes(x, i);
                    d.uniteNodes(x, x/i);
                }
            }
        }
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> root;
        for(int x:nums){
            int r=d.findNode(x);
            root[r].push(x);
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int r=d.findNode(nums[i]);
            res[i]=root[r].top();
            root[r].pop();
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++) if(nums[i]!=res[i]) return false;
        return true;
    }
};