/* 
Problem ID : 1339 

Problem : Maximum Product of Splitted Binary Tree

Statement : Given the root of a binary tree, split the binary tree into two subtrees by removing 
one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, 
return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.
*/

/* Problem Link
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07
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
    const int MOD=1e9+7;
    long long total=0, ans=INT_MIN;
    int dfs(TreeNode* Node, bool flag){
        if(Node==NULL) return 0;
        int sum=Node->val+dfs(Node->left,flag)+dfs(Node->right, flag);
        if(flag) ans=max(ans, (total-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        total=dfs(root,false);
        dfs(root,true);
        return ans%MOD;
    }
};