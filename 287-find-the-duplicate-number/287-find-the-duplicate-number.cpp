class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int ans;
        for(int x:nums){
            if(mp[x]){
                ans = x;
                break;
            }
            mp[x] = true;
        }
        return ans;
    }
};