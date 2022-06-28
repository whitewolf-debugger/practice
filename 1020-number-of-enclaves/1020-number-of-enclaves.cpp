class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i ,int j,int ROWS ,int COLS,vector<vector<bool>>& visited,int &count){
        if(i<0 || j<0 || i>=ROWS || j>=COLS || grid[i][j]==0 || visited[i][j]) return;
        visited[i][j]=true;
        count++;
        //dfs calls on all 4 directions 
        dfs(grid,i+1,j,ROWS,COLS,visited,count);
        dfs(grid,i,j+1,ROWS,COLS,visited,count);
        dfs(grid,i-1,j,ROWS,COLS,visited,count);
        dfs(grid,i,j-1,ROWS,COLS,visited,count);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count =0;
        int ones =0;
        //calculating total number of ones 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) ones++;
            }
        }
       //if a land cell is on the boundary we run a dfs from that cell to mark all the reachable cells from that cell.
        //first col i,0 calculated connected 1 and mark visited
        for(int i=0;i<m;i++){
            if(!visited[i][0] && grid[i][0]==1){
                dfs(grid,i,0,m,n,visited,count);
            }
        }
        //first row  0,i calculated connected 1 and mark visited
        for(int i=0;i<n;i++){
            if(!visited[0][i] && grid[0][i]==1){
                dfs(grid,0,i,m,n,visited,count);
            }
        }
        //last column i,n-1 calculated connected 1 and mark visited
        for(int i=0;i<m;i++){
            if(!visited[i][n-1] && grid[i][n-1]==1){
                dfs(grid,i,n-1,m,n,visited,count);
            }
        }
        //last row m-1,i calculated connected 1 and mark visited 
        for(int i=0;i<n;i++){
            if(!visited[m-1][i] && grid[m-1][i]==1){
                dfs(grid,m-1,i,m,n,visited,count);
            }
        }
        return (ones-count);
    }
};