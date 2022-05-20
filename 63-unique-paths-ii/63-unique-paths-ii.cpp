class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>>& dp,int i,int j){
        if(i<0 || j<0 || j>=n || i>=m || obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return 1;
        int path =0;
        path+=dfs(obstacleGrid,m,n,dp,i+1,j)+dfs(obstacleGrid,m,n,dp,i,j+1);
        dp[i][j] = path;
        return path;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(obstacleGrid,m,n,dp,0,0);
    }
};