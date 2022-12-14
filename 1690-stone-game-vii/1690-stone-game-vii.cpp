class Solution {
public:
    int dp(vector<int>& stones, int L , int R, int sum,vector<vector<int>> &memo) {
        if(L > R) return 0;
        if(sum <= 0) return 0;
        if(memo[L][R] != -1) return memo[L][R];
        int takeLeft = sum - stones[L] - dp(stones, L + 1 , R,sum - stones[L], memo);
        int takeRight = sum - stones[R] - dp(stones, L  , R - 1,sum - stones[R], memo);
        
        int profit = max(takeLeft, takeRight);
        return memo[L][R] = profit;
    }
    
    int stoneGameVII(vector<int>& stones) {
        int sum = 0 ;
        
        int n = stones.size();
            
        for(int i =0 ; i < n;i++) {
            sum += stones[i];
        }
        
        vector<vector<int>> memo(1000,vector<int>(1000,-1));
        int value = dp(stones, 0 , n-1,sum,memo);
        return value;
        
        
    }
};