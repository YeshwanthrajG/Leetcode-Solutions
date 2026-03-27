/* 
Problem ID : 460 

Problem : LFU Cache

Statement : Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already 
present. When the cache reaches its capacity, it should invalidate and remove the least frequently used 
key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the 
same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. 
The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). 
The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/

/* Problem Link
https://leetcode.com/problems/lfu-cache/description/
*/

class LFUCache {
public:
    class Node{
    public:
        int k,v,cnt;
        Node *prev, *next;
        Node(int key, int val){
            k=key;
            v=val;
            this->cnt=1;
            prev=nullptr;
            next=nullptr;
        }
    };

    class List{
    public:
        int n;
        Node *head, *tail;
        List(){
            head=new Node(-1, -1);
            tail=new Node(-1, -1);
            head->next=tail;
            tail->prev=head;
            n=0;
        }

        void delNode(Node *node){
            node->prev->next=node->next;
            node->next->prev=node->prev;
            n--;
        }

        void insertNode(Node *node){
            node->next=head->next;
            head->next->prev=node;
            head->next=node;
            node->prev=head;
            n++;
        }
    };

    int cap, currN, minF;
    map<int, Node*> cache;
    map<int, List*> freq;

    LFUCache(int capacity) {
        cap=capacity;
        currN=0;
        minF=0;
    }

    void updateData(Node *node){
        freq[node->cnt]->delNode(node);
        if(node->cnt==minF && freq[node->cnt]->n==0) minF++;
        List *list=new List();
        if(freq.find(node->cnt+1)!=freq.end()) list=freq[node->cnt+1];
        node->cnt++;
        list->insertNode(node);
        freq[node->cnt]=list;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node=cache[key];
            updateData(node);
            return node->v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0) return ;
        if(cache.find(key)!=cache.end()){
            Node* node=cache[key];
            node->v=value;
            updateData(node);
        }
        else{
            if(currN>=cap){
                Node *node=freq[minF]->tail->prev;
                cache.erase(node->k);
                freq[minF]->delNode(node);
                currN--;
            }
            Node *newNode=new Node(key, value);
            minF=1;
            List *list=new List();
            if(freq.find(minF)!=freq.end()) list=freq[minF];
            list->insertNode(newNode);
            freq[minF]=list;
            cache[key]=newNode;
            currN++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */