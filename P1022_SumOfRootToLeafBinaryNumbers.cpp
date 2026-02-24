/* 
Problem ID : 1022 

Problem : Sum of Root To Leaf Binary Numbers

Statement : You are given the root of a binary tree where each node has a value 0 or 1. 
Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. 
Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/?envType=daily-question&envId=2026-02-24
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
    int dfs(TreeNode* root, int x){
        if(!root) return 0;
        x=x*2+root->val;
        if(!root->left && !root->right) return x;
        return dfs(root->left, x)+dfs(root->right, x);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};