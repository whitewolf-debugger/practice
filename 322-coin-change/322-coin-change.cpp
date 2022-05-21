// Pure Recursion : TC : O(2^N)
class Solution {
public:
    //dp is array used for memoisation
     int dp[13][10001];
    int helper(vector<int> &coins, int index, int target){
        // when we get the combination return 0
        if(target == 0) return 0;
        // if we donot get the combination
        if(index == 0) return INT_MAX-1;
        if(dp[index][target]!=-1) return dp[index][target];
        if(coins[index-1] <= target){
            // wecan take or not take onlt when the denomination is less than or equal to the required amount of coins
            // minimum of we take this coin or we donot take this coin
            //since we can take a coin multiple time we are not doing index-1 in the case 
            int  take = 1 + helper(coins,index, target-coins[index-1]);
            // case 2 we donot take this coin
            int notTake = helper(coins, index-1, target);
            return dp[index][target] = min(take,notTake);
        }
        // if the coin is greater target then we move to next coin
        return dp[index][target] = helper(coins, index-1, target);
    }
    int coinChange(vector<int>& coins, int amount){
        // setting -1 in every position of dp array used for memoisation
        memset(dp, -1, sizeof(dp));
        int minCoins = helper(coins, coins.size(), amount);
         return minCoins == INT_MAX-1  ? -1 : minCoins;
    }
};