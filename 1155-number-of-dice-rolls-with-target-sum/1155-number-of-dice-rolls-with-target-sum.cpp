class Solution {
public:
    long long MOD = 1e9+7;
    long long Dp(int n,int k,int target,vector<vector<long long>> & cache) {
        if(n == 0 && target == 0) return 1;
        //check if n and target goes out of bounds then in caching it will give error so we return 0
        if(n < 0  || target < 0) return 0;
        if(cache[n][target] != -1) return cache[n][target];
        long long ans = 0;
        for(int i =1 ; i <= k;i++) {
            if(target - i >= 0) {
                ans += Dp(n-1,k,target-i,cache)%MOD;
            }
        }
        return cache[n][target] = ans%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> cache(31,vector<long long>(1001,-1));
        return Dp(n,k,target,cache);
    }
};