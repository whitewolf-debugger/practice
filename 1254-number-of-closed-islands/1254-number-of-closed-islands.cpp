class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int m,int n,int row,int col){
        if(grid[row][col]==1 || grid[row][col]==-1) return true;
        if(row==m-1 || col==n-1 || col==0 || row==0) return false;
        grid[row][col]=-1;
        bool left = dfs(grid,m,n,row,col-1);
        bool up = dfs(grid,m,n,row-1,col);
        bool right = dfs(grid,m,n,row,col+1);
        bool down = dfs(grid,m,n,row+1,col);
        return left && up && right && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                   if(dfs(grid,m,n,i,j))
                       ans++;
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     bool dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
//         if(grid[i][j]==1 or grid[i][j]==-1)
//             return true;
//         if(i==0 or j==0 or i==m-1 or j==n-1)
//             return false;
        
//         grid[i][j]=-1;
//         //left
//         bool left = dfs(grid,i,j-1,m,n);
//         //up
//         bool up = dfs(grid,i-1,j,m,n);
//         //right
//         bool right = dfs(grid,i,j+1,m,n);
//         //down
//         bool down = dfs(grid,i+1,j,m,n);
        
//         return left && up && right && down;
        
//     }
//     int closedIsland(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int count=0;
//         for(int i=1;i<m-1;i++){
//             for(int j=1;j<n-1;j++){
//                 if(grid[i][j]==0){
//                     if(dfs(grid,i,j,m,n))
//                         count++;
//                 }
//             }
//         }
        
//         return count;
//     }
// };