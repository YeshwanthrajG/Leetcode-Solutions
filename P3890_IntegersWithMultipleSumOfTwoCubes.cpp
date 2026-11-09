/* 
Problem ID : 3890 

Problem : Integers With Multiple Sum of Two Cubes

Statement : You are given an integer n.

An integer x is considered good if there exist at least two distinct pairs (a, b) such that:

a and b are positive integers.
a <= b
x = a3 + b3
Return an array containing all good integers less than or equal to n, sorted in ascending order.
*/

/* Problem Link
https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/description/
*/

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> map;
        int lim=cbrt(n)+1;
        vector<long long> cube(lim+1);
        for(int i=1;i<=lim;i++) cube[i]=1LL*i*i*i;
        for(int a=1;a<=lim;a++){
            for(int b=a;b<=lim;b++){
                long long sum=cube[a]+cube[b];
                if(sum>n) break;
                map[(int)sum]++;
            }
        }
        vector<int> res;
        for(auto &e:map){
            if(e.second>=2) res.push_back(e.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};