/* 
Problem ID : 380 

Problem : Insert Delete GetRandom O(1)

Statement : Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.

bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was 
not present, false otherwise.

bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, 
false otherwise.

int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least 
one element exists when this method is called). Each element must have the same probability of being 
returned.

You must implement the functions of the class such that each function works in average O(1) time 
complexity.
*/

/* Problem Link
https://leetcode.com/problems/insert-delete-getrandom-o1/description/
*/

class RandomizedSet {
public:
    vector<int> a;
    unordered_map<int, int> map;

    RandomizedSet() {
        
    }

    bool search(int val){
        if(map.find(val)!=map.end()) return true;
        return false;
    }
    
    bool insert(int val) {
        if(search(val)) return false;
        a.push_back(val);
        map[val]=a.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val)) return false;
        auto it=map.find(val);
        int temp=it->second;
        a[temp]=a.back();
        a.pop_back();
        map[a[temp]]=temp;
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */