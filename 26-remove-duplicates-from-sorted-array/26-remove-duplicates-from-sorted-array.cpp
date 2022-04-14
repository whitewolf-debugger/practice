class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            v.push_back(x.first);
        }
        sort(v.begin(),v.end());
        nums = v;
        return v.size();
    }
};