/* 
Problem ID : 3845 

Problem : Maximum Subarray XOR with Bounded Range

Statement : You are given a non-negative integer array nums and an integer k.

You must select a subarray of nums such that the difference between its maximum and minimum elements is 
at most k. The value of this subarray is the bitwise XOR of all elements in the subarray.

Return an integer denoting the maximum possible value of the selected subarray.
*/

/* Problem Link
https://leetcode.com/problems/maximum-subarray-xor-with-bounded-range/description/
*/

struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
    int count = 0;
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 14; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
            node->count++;
        }
    }

    void remove(int num) {
        TrieNode* node = root;
        for (int i = 14; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit] || node->child[bit]->count == 0) return;
            node = node->child[bit];
            node->count--;
        }
    }

    int query(int num) {
        TrieNode* node = root;
        int res = 0;
        for (int i = 14; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[bit ^ 1] && node->child[bit ^ 1]->count > 0) {
                res |= (1 << i);
                node = node->child[bit ^ 1];
            } else if (node->child[bit]) {
                node = node->child[bit];
            } else {
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size(), maxXOR = 0;

        deque<int> minQ, maxQ;
        Trie trie;
        vector<int> prefixXOR(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefixXOR[i + 1] = prefixXOR[i] ^ nums[i];

        trie.insert(0);

        int l = 0;
        for (int r = 0; r < n; r++) {
            while (!minQ.empty() && nums[r] < nums[minQ.back()]) minQ.pop_back();
            minQ.push_back(r);

            while (!maxQ.empty() && nums[r] > nums[maxQ.back()]) maxQ.pop_back();
            maxQ.push_back(r);

            while (nums[maxQ.front()] - nums[minQ.front()] > k) {
                trie.remove(prefixXOR[l]);
                if (minQ.front() == l) minQ.pop_front();
                if (maxQ.front() == l) maxQ.pop_front();
                l++;
            }

            maxXOR = max(maxXOR, trie.query(prefixXOR[r + 1])); 
            trie.insert(prefixXOR[r + 1]); 
        }

        return maxXOR;
    }
};
