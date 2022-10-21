class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        for(int i =0; i < nums.size();i++) {
            mp[nums[i]] . push_back(i);
        }
        for(auto& x: mp) {
            if(x.second.size() > 1) {
                for(int i =0 ; i < x.second.size()-1;i++) {
                    if(abs(x.second[i] - x.second[i+1])<= k) return true;
                }
            }
        }
        return false;
    }
};