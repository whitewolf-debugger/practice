class MyHashMap {
public:
    unordered_map<int,int> mp;
    unordered_map<int,bool> freqMap;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        mp[key] = value;
        freqMap[key]=true;
    }
    
    int get(int key) {
            if(freqMap[key])
                return mp[key];
        return -1;
    }
    void remove(int key) {
        freqMap[key]=false;
        mp[key]=-1;   
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */