// Pure Recursion : TC : O(2^N)
class Solution {
public:
     int dp[13][10001];
    int helper(vector<int> &coins, int index, int target){
        if(target == 0) return 0;
        if(index == 0) return INT_MAX-1;
        if(dp[index][target]!=-1) return dp[index][target];
        if(coins[index-1] <= target){
            return dp[index][target] = min(1 + helper(coins,index, target-coins[index-1]), helper(coins, index-1, target));
        }
        return dp[index][target] = helper(coins, index-1, target);
    }
    int coinChange(vector<int>& coins, int amount){
        memset(dp, -1, sizeof(dp));
        int minCoins = helper(coins, coins.size(), amount);
         return minCoins == INT_MAX-1  ? -1 : minCoins;
    }
};