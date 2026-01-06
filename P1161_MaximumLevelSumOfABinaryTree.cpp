/* 
Problem ID : 1161 

Problem : Maximum Level Sum of a Binary Tree

Statement : Given the root of a binary tree, the level of its root is 1, the level of its children is 2, 
and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
*/

/* Problem Link
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> sum={INT_MIN};
    void dfs(TreeNode* Node, int level=1){
        if(Node==NULL) return;
        int temp=Node->val;
        if(sum.size()==level) sum.push_back(temp);
        else sum[level]+=temp;
        dfs(Node->left, level+1);
        dfs(Node->right, level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root);
        return max_element(sum.begin(), sum.end())-sum.begin();
    }
};