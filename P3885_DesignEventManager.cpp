/* 
Problem ID : 3885 

Problem : Design Event Manager

Statement : You are given an initial list of events, where each event has a unique eventId and a priority.

Implement the EventManager class:

EventManager(int[][] events) Initializes the manager with the given events, 
where events[i] = [eventIdi, priority​​​​​​​i].
void updatePriority(int eventId, int newPriority) Updates the priority of the active event with 
id eventId to newPriority.
int pollHighest() Removes and returns the eventId of the active event with the highest priority. 
If multiple active events have the same priority, return the smallest eventId among them. If there are 
no active events, return -1.
An event is called active if it has not been removed by pollHighest().
*/

/* Problem Link
https://leetcode.com/problems/design-event-manager/description/
*/

class EventManager {
public:
    set<pair<int, int>> st;
    unordered_map<int, int> mp;
    
    EventManager(vector<vector<int>>& events) {
        for(auto &e:events){
            int id=e[0];
            int priority=e[1];
            st.insert({-priority, id});
            mp[id]=priority;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int old=mp[eventId];
        st.erase({-old, eventId});
        st.insert({-newPriority, eventId});
        mp[eventId]=newPriority;
    }
    
    int pollHighest() {
        if(st.empty()){
           return -1; 
        }
        auto it=st.begin();
        int eventId=it->second;
        st.erase(it);
        mp.erase(eventId);
        return eventId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */