class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>=2){
                mp[nums[i]]-=2;
                ans[0]++;
            }
        }
        for(auto& x:mp){
            if(x.second>0){
                ans[1]++;
            }
        }
        return ans;
    }
};