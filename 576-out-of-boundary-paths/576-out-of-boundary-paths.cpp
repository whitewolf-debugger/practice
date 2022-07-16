class Solution {
public:
     long long mod = 1e9 + 7;
    bool isInside(int i,int j,int m, int n){
        if(i>=0 && j>=0 && i<m && j<n){
            return true;
        }
        return false;
    }
    int dfs(int i,int j,int m, int n, int moves,vector<vector<vector<int>>> &dp){
        if(!isInside(i,j,m,n)){
            return 1;
        }
        if(moves<=0) return 0;
         if(dp[i][j][moves]!=-1) return dp[i][j][moves];
        int left =dfs(i-1,j,m,n,moves-1,dp);
        int right =dfs(i+1,j,m,n,moves-1,dp);
        int up =dfs(i,j-1,m,n,moves-1,dp);
        int down =dfs(i,j+1,m,n,moves-1,dp);
        return dp[i][j][moves] = (left%mod+right%mod+up%mod+down%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(51,vector<vector<int>>(51,vector<int>(51,-1)));
        return dfs(startRow,startColumn,m,n,maxMove,dp);
    }
};