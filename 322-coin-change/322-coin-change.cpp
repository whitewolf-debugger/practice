class Solution {
public:
    int memo[13][10001];
    // Unbounded KnapSack 
    int rec(vector<int> &coins, int n, int W){
        if(W == 0) return 0;
        
        if(n == 0) return INT_MAX-1;
        
        // Memoization Stuff
        if(memo[n][W] != -1) return memo[n][W];
        
        if(coins[n-1] <= W){
            return memo[n][W] = min(1 + rec(coins, n, W-coins[n-1]), rec(coins, n-1, W));
        }
        
        return memo[n][W] = rec(coins, n-1, W);
    }
    int coinChange(vector<int>& coins, int amount){
        memset(memo, -1, sizeof(memo));
        int minCoins = rec(coins, coins.size(), amount);
        return minCoins == INT_MAX-1  ? -1 : minCoins;
    }
};