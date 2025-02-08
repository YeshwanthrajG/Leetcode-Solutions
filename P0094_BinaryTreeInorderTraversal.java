/* 
Problem ID : 94 

Problem : Binary Tree Inorder Traversal

Statement : Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/* Problem Link
https://leetcode.com/problems/binary-tree-inorder-traversal/description/
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list=new ArrayList<>();
        inorder(root,list);
        return list;
    }
    
    private void inorder(TreeNode root, List<Integer> list)
    {
        if(root==null)
            return;

        inorder(root.left,list);
        list.add(root.val);
        inorder(root.right,list);
    }
}