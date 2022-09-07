class Solution {
public:
    int dfs(vector<int>& coins,int amount,int i,vector<vector<int>>& cache){
        if(amount < 0 || i >= coins.size()){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(cache[i][amount] != -1) return cache[i][amount];
        int take = 0;
        if(coins[i] <= amount){
           take += dfs(coins,amount - coins[i],i,cache); 
        }
        int notTake = dfs(coins,amount,i+1,cache); 
            
        return cache[i][amount] = (take+notTake);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> cache(305,vector<int>(5005,-1));
        return dfs(coins,amount,0,cache);
    }
};