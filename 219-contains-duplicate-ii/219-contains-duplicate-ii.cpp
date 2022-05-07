class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto x:mp){
            if(x.second.size()<2) continue;
            vector<int> v = x.second;
            for(int i=0;i<v.size();i++){
                for(int j=i+1;j<v.size();j++){
                    if(abs(v[j]-v[i])<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
/*
    0 1 2 3
    1 2 3 1
    
    1:{0,3};
    2:{1};
    3:{2};











*/