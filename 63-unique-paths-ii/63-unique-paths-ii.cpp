class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>>& dp,int i,int j){
        // if the index is not in range  or we encounter an obstacle return 0
        if(i<0 || j<0 || j>=n || i>=m || obstacleGrid[i][j]==1) return 0;
        // dp is used for memoisation
        if(dp[i][j]!=-1) return dp[i][j];
        // if we are at last index after explaring a path we return 1 
        if(i==m-1 && j==n-1) return 1;
        int path =0;
        path+=dfs(obstacleGrid,m,n,dp,i+1,j)+dfs(obstacleGrid,m,n,dp,i,j+1);
        dp[i][j] = path;
        return path;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //dp array with -1 as default value 
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(obstacleGrid,m,n,dp,0,0);
    }
};
/*
   x -> y
   ↓
   z
  
   
   path from x to m-1 n-1 inthe array is path from y(x+1,y) + path from z(x,y+1)

*/