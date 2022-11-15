class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        unordered_map<int , int> mp;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        for(int i =0; i < nums.size();i++) {
            if(mp[nums[i]] <= 0) {
               continue; 
            }
            int end = nums[i] + k;
            for(int start = nums[i]; start < end; start++) {
                if(mp[start] <= 0) return false;
                mp[start]--;
            }  
        }
        return true;
    }
};