class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n = changed.size();
        vector<int> original;
        if(n == 0 || n%2 != 0){
            return original;
        }
        sort(changed.begin(),changed.end());
        vector<int> ans;
        unordered_map<int,int> mp;
    
        for(int i =0; i < n; i++){
            mp[changed[i]]++;
        }
        
        for(auto & x : changed){
            
            if(x != 0 && mp[x] > 0 && mp[2*x] > 0){
                original.push_back(x);
                mp[x]--;
                mp[2*x]--;
            }
            if(x == 0 && mp[x] > 1){
                original.push_back(x);
                mp[x] -= 2;
            }
        }
        
       if(n != 2*original.size()){
           return {};
       }
        return original;
    }
};