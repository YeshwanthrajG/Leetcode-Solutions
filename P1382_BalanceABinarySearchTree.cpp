/* 
Problem ID : 1382 

Problem : Balance a Binary Search Tree

Statement : Given the root of a binary search tree, return a balanced binary search tree with the 
same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by 
more than 1.
*/

/* Problem Link
https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return build(v, 0, (int)v.size()-1);
    }
    void inorder(TreeNode* node, vector<int>& v){
        if(!node) return;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
    TreeNode* build(const vector<int> &v, int l, int r){
        if(l>r) return nullptr;
        int mid=(l+r)/2;
        TreeNode* node=new TreeNode(v[mid]);
        node->left=build(v, l, mid-1);
        node->right=build(v, mid+1, r);
        return node;
    }
};