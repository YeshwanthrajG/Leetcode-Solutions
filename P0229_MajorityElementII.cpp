/* 
Problem ID : 229 

Problem : Majority Element II

Statement : Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.
*/

/* Problem Link
https://leetcode.com/problems/majority-element-ii/description/
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0, count2=0, candidate1=0, candidate2=0;
        for(int i=0;i<n;i++){
            if(count1==0 && candidate2!=nums[i]) {
                count1=1;
                candidate1=nums[i];
            }
            else if(count2==0 && candidate1!=nums[i]){
                count2=1;
                candidate2=nums[i];
            }
            else if(candidate1==nums[i]) count1++;
            else if(candidate2==nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1=0, count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate1) count1++;
            else if(nums[i]==candidate2) count2++;
        }
        vector<int> res;
        int th=n/3;
        if(count1>th) res.push_back(candidate1);
        if(count2>th) res.push_back(candidate2);
        return res;
    }
};