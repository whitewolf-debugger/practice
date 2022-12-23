class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2,vector<int>(2, 0));
        
        for(int i = n-1; i >=0 ;i--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0] ,0 + dp[i+1][1]);
                } else {
                    dp[i][buy] = max(prices[i] + dp[i + 2][1] ,0 + dp[i+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }

};


//     int dp(vector<int> prices, int i,bool buy,vector<vector<int>> &cache) {
//         if(i >= prices.size()) return 0;
//         int profit = 0;
//         if(cache[i][buy] != -1) return cache[i][buy];
//         if(buy) {
//             //option 1 buy the stocks
//             int op1 = -prices[i] + dp(prices, i+1, false,cache);
            
//             //option 2 donot buy it
//             int op2 =  dp(prices, i+1, buy,cache);
//             profit = max(op1, op2);
            
//         } else {
//             //sell it 
//             int op1 = prices[i] + dp(prices, i+2, true,cache);
            
            
//             //donot sell it
//             int op2 =  dp(prices, i+1, buy,cache);
            
//             profit = max(op1, op2);
//         }
        
//         return cache[i][buy] = profit;
//     }
    
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int profit = 0;
//         vector<vector<int>> cache(n , vector<int>(2, -1));
//         profit = dp(prices, 0,true,cache);
//         return profit;
//     }