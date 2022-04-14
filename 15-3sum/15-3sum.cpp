class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        vector<vector<int>>ans;
        
        if(n < 3) return ans;
        
        for(int i = 0 ; i < n ; i++){
            if(i>0 && nums[i] == nums[i-1])continue;
               int req = 0 - nums[i];
                for(int j = i + 1 ; j < n ; j++){
                    if(j > i + 1 && nums[j] == nums[j-1])continue;
                    auto it = upper_bound(nums.begin() + j + 1,nums.end(),req-nums[j]);
                    it--;
                    if(*it == 0-nums[i]-nums[j] && it-nums.begin()!=j){

                        vector<int>tmp;

                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(*it);

                        ans.push_back(tmp);
                    }
                }
        }
        return ans;
    }
};