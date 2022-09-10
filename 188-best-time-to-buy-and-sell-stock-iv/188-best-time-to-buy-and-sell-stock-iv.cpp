class Solution {
public:
    int dp(vector<int> &prices,int index,int n,int k,int b,vector<vector<vector<int>>>& cache){
        if(k == 0 || index>= n){
            return 0;
        }
        if(cache[index][b][k] != -1) return cache[index][b][k];
        int buy = 0;
        int sell = 0;
        if(b == 1){
          buy += max(-prices[index]+dp(prices,index+1,n,k,0,cache),dp(prices,index+1,n,k,1,cache));
        } else{
            sell += max(prices[index]+dp(prices,index+1,n,k-1,1,cache),dp(prices,index+1,n,k,0,cache));
        }
        return cache[index][b][k] = max(buy,sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> cache(1001,vector<vector<int>>(2,vector<int>(101,-1)));
        return dp(prices,0,prices.size(),k,1,cache);
    }
};