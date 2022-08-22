class Solution {
public:
    int dfs(vector<int>& prices,int i,int buy,int n,vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy == 1){
            
            //buy
            profit  = max(-prices[i]+dfs(prices,i+1,0,n,dp) ,dfs(prices,i+1,1,n,dp));
        } else{
    
            //sell
            profit  = max(prices[i]+dfs(prices,i+1,1,n,dp) ,dfs(prices,i+1,0,n,dp));
        }
        
        return dp[i][buy] = profit;
        

    }
    int maxProfit(vector<int>& prices) {
        
        int i =0;
        int buy = 1;
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return dfs(prices,i,buy,n,dp);
        
    }
};
/*

    
    
    7   1   5   3   6   4
    ^



*/