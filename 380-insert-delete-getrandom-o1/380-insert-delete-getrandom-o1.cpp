class RandomizedSet {
public:
    unordered_set<int> set;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val)==set.end()){
            set.insert(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(set.find(val)!=set.end()){
            set.erase(set.find(val));
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        auto it = set.cbegin();
        int random = rand() % set.size();
        std::advance(it, random);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */