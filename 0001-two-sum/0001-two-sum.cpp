class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,vector<int>> mp;
        for(int i =0; i < nums.size();i++) {
            mp[nums[i]].push_back(i);
        }
        unordered_set<int> skip;
        vector<int> ans;
        for(int i =0; i < nums.size();i++) {
            if(skip.find(i) != skip.end()) continue;
            int diff = target - nums[i];
            if( diff == nums[i]) {
                if(mp[nums[i]].size() >=2) {
                   
                    int count = 0;
                    while(count < 2){
                        auto it = mp[nums[i]].begin();
                        ans.push_back(*it);
                        mp[nums[i]].erase(it);
                        count++;
                        skip.insert(*it);
                    }
                }
            } else {
                if(mp[diff].size() > 0) {
                    auto it = mp[diff].begin();
                    ans.push_back(i);
                    ans.push_back(*it);
                    skip.insert(*it);
                    mp[diff].erase(it);
                    
                }
            }
        }
        return ans;
    }
};