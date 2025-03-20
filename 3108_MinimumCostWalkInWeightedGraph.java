/* 
Problem ID : 3108 

Problem : Minimum Cost Walk in Weighted Graph

Statement : There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge 
between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge 
connects the vertex that comes before it and the vertex that comes after it. It's important to note that a 
walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the 
edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk 
is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise 
AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum 
cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.
*/

/* Problem Link
https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/?envType=daily-question&envId=2025-03-20
*/

class Solution {
    int[] parent;
    int[] minPathCost;

    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        parent=new int[n];
        minPathCost=new int[n];
        Arrays.fill(minPathCost,-1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int[] i:edges)
        {
            int source=i[0];
            int target=i[1];
            int weight=i[2];
            int sourceRoot=findRoot(source);
            int targetRoot=findRoot(target);
            if(minPathCost[sourceRoot]==-1)
                minPathCost[sourceRoot]&=weight;
            else
                minPathCost[sourceRoot]&=weight;
            if(minPathCost[targetRoot]==-1)
                minPathCost[targetRoot]=weight;
            else
                minPathCost[targetRoot]&=weight;

            if(sourceRoot!=targetRoot)
            {
                parent[sourceRoot]=targetRoot;
                minPathCost[targetRoot]&=minPathCost[sourceRoot];
            }
        }
        int[] res=new int[query.length];
        for(int i=0;i<query.length;i++)
        {
            int st=query[i][0];
            int end=query[i][1];
            if(st==end)
                res[i]=0;
            else if(findRoot(st)!=findRoot(end))
                res[i]=-1;
            else
                res[i]=minPathCost[findRoot(st)];
        }
        return res;
    }

    private int findRoot(int node)
    {
        if(parent[node]!=node)
            parent[node]=findRoot(parent[node]);
        return parent[node];
    }
}