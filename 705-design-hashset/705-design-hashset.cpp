class MyHashSet {
public:
    unordered_map<int,bool> mp;
    MyHashSet() {
       
    }
    
    void add(int key) {
        mp[key]=true;
    }
    
    void remove(int key) {
        mp[key] = false;
    }
    
    bool contains(int key) {
        return mp[key];
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */