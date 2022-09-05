class Solution {
public:
    long long MOD = 1e9 + 7;
    long long dfs(int startPos, int endPos, int k,vector<vector<long long>> &dp){
        if(k == 0){
            if(startPos == endPos){
                return 1;
            } else{
                return 0;
            }
        }
        if(dp[startPos+1000][k] != -1) return  dp[startPos+1000][k];
        long long ways  = 0;
        // reduce the start
        ways = (ways % MOD + dfs(startPos-1,endPos,k-1,dp) % MOD) % MOD;
        //increase the start
        ways = (ways % MOD + dfs(startPos+1,endPos,k-1,dp) % MOD) % MOD;
        
        return dp[startPos+1000][k] = ways;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<long long>> dp(3005,vector<long long>(1005,-1));
        return dfs(startPos,endPos,k,dp);
    }
};