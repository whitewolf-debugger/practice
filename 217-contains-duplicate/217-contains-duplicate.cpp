class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        for(auto i : mp){
            if(i.second >= 2){
                return true;
            }
        }
        return false;
    }
};