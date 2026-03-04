/* 
Problem ID : 146 

Problem : LRU Cache

Statement : Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

/* Problem Link
https://leetcode.com/problems/lru-cache/description/
*/

class LRUCache {
    struct Node{
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };
    int c;
    unordered_map<int, Node*> map;
    Node *head=new Node(-1, -1), *tail=new Node(-1, -1);

public:
    LRUCache(int capacity) {
        c=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void add(Node* newNode){
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void del(Node* node){
        Node *prevN=node->prev;
        Node* nextN=node->next;
        prevN->next=nextN;
        nextN->prev=prevN;
    }
    
    int get(int key) {
        if(map.find(key)!=map.end()){
            Node *temp=map[key];
            int ans=temp->val;
            map.erase(key);
            del(temp);
            add(temp);
            map[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            Node* exist=map[key];
            map.erase(key);
            del(exist);
        }
        if(map.size()==c){
            map.erase(tail->prev->key);
            del(tail->prev);
        }
        add(new Node(key, value));
        map[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */