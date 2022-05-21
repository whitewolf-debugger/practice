// Pure Recursion : TC : O(2^N)
class Solution {
public:
     int dp[13][10001];
    // Unbounded KnapSack 
    int rec(vector<int> &coins, int n, int W){

        if(W == 0) return 0;

        if(n == 0) return INT_MAX-1;
        if(dp[n][W]!=-1) return dp[n][W];
        if(coins[n-1] <= W){
            return dp[n][W] = min(1 + rec(coins, n, W-coins[n-1]), rec(coins, n-1, W));
        }
        return dp[n][W] = rec(coins, n-1, W);
    }
    int coinChange(vector<int>& coins, int amount){
        memset(dp, -1, sizeof(dp));
        int minCoins = rec(coins, coins.size(), amount);
        return minCoins == INT_MAX-1  ? -1 : minCoins;
    }
};