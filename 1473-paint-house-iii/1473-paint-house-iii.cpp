class Solution {
public:
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,int start,int prev_color,vector<vector<vector<int>>> &memo){
        if(start==m && target ==0) return 0;
        if(start==m || target<0 ) return INT_MAX;
        if(prev_color != -1 && target != -1 && memo[start][prev_color][target]!=-1){
            return memo[start][prev_color][target];
        }
        int mincost =INT_MAX;
        if(houses[start]!=0){
            int currcost = 0;
            if(prev_color == houses[start]){
                currcost=dfs(houses,cost,m,n,target,start+1,houses[start],memo);
            }
            else{
                currcost=dfs(houses,cost,m,n,target-1,start+1,houses[start],memo);
            }
            mincost = min(mincost,currcost);
        }
        else{
            for(int j=0;j<n;j++){
                int currcost = 0;
                if(prev_color==j+1){
                    currcost=dfs(houses,cost,m,n,target,start+1,j+1,memo);
                }else{
                    currcost=dfs(houses,cost,m,n,target-1,start+1,j+1,memo);
                }
                if(currcost!=INT_MAX){
                    mincost = min(mincost,currcost+cost[start][j]);
                }
            }
        }
        if(prev_color != -1 && target != -1){
            memo[start][prev_color][target] = mincost;
        }
        return  mincost;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> memo(m+3,vector<vector<int>>(n+3,vector<int>(m+3,-1)));
        int min_cost = dfs(houses,cost,m,n,target,0,-1,memo);
        return min_cost == INT_MAX ? -1 : min_cost;
    }
};