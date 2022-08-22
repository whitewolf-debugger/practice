class Solution {
public:
    int dfs(vector<int>& nums,int ind, int lastind,vector<int> &dp){
        if(ind > lastind){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        //not take
        int nottake = dfs(nums,ind+1,lastind,dp);
        int take = nums[ind] + dfs(nums,ind+2,lastind,dp);    
        return dp[ind] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+1 , -1);
        vector<int> dp2(n+1 , -1);
        return max(dfs(nums,1,n-1,dp1) , dfs(nums,0,n-2,dp2));
    }
};