class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxelement = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            maxelement = max(maxelement,nums[i]);
        }
        
        vector<int> index;
        for(int i =0 ; i < nums.size();i++) {
            if(nums[i] == maxelement) {
                index.push_back(i);
            }
        }
        int ans  =0;
        int size = index.size();
        vector<int> dp(size,0);
        for(int i =1 ;i < index.size();i++){
            if(index[i] - index[i-1] == 1) {
                dp[i] = dp[i-1] + 1;
                ans = max(ans,dp[i]);
            }
        }
        
        return ans+1;
    }
    
};