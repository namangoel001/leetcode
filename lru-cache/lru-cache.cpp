class LRUCache {
public:
    int cap;
    list<int> l1;
    unordered_map<int,pair<int,list<int>::iterator>> mp;
    void change_pos(int key)
    {
        l1.erase(mp[key].second);
        l1.push_front(key);
        mp[key].second=l1.begin();
    }
    LRUCache(int capacity) {
        cap=capacity;
    }
    int get(int key) {
     if(mp.find(key)!=mp.end())
     {
         change_pos(key);
         return mp[key].first;
     }
        return -1;
    }
    
    void put(int key, int value) {
    if(mp.find(key)!=mp.end())
    {
        change_pos(key);
        mp[key].first=value;
    }
    else
    {
        l1.push_front(key);
        mp[key].first=value;
        mp[key].second=l1.begin();
        cap--;
    }
    if(cap<0)
    {
        mp.erase(l1.back());
        l1.pop_back();
        cap++;
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */