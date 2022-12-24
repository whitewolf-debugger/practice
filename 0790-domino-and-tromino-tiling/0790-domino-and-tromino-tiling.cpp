class Solution {
public:
    int MOD = 1e9 + 7;
    int dp(int n,vector<int>& cache) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(cache[n] != -1) return cache[n];
        return cache[n] = ((2*dp(n-1,cache))% MOD + (dp(n-3,cache))%MOD)%MOD;
    }
    int numTilings(int n) {
        vector<int> cache(n + 1,-1);
        return dp(n,cache);
    }
};