/* 
Problem ID : 3372 

Problem : Maximize the Number of Target Nodes After Connecting Trees I

Statement : There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] 
and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where 
edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and 
edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. 
You are also given an integer k.

Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. 
Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to 
node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
Note that queries are independent from each other. That is, for every query you will remove the added 
edge before proceeding to the next query.
*/

/* Problem Link
https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-question&envId=2025-05-28
*/

class Solution {
    private List<List<Integer>> buildList(int[][] edges) {
        int n = edges.length + 1;
        List<List<Integer>> adj = new ArrayList<>(n);
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        return adj;
    }

    private int dfs(List<List<Integer>> adj, int u, int p, int k) {
        if (k < 0) return 0;
        int cnt = 1;
        for (int v : adj.get(u)) {
            if (v != p) cnt += dfs(adj, v, u, k - 1);
        }
        return cnt;
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        List<List<Integer>> adj1 = buildList(edges1);
        List<List<Integer>> adj2 = buildList(edges2);
        int m = adj2.size(), maxiB = 0;
        for (int i = 0; i < m; i++) {
            maxiB = Math.max(maxiB, dfs(adj2, i, -1, k - 1));
        }
        int n = adj1.size();
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = dfs(adj1, i, -1, k) + maxiB;
        }
        return res;
    }
}