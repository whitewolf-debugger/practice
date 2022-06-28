class Solution {
public:
    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<bool>>& visited,int row,int col,int m,int n,int &flag ){
        if(row<0 || col<0 || row>=m || col>=n|| grid2[row][col]==0 || visited[row][col] ) return;
        if(grid2[row][col]==1){
            if(grid1[row][col]==0) {
                flag=0;
                return;
            }
            visited[row][col]=true;
        }
        dfs(grid1,grid2,visited,row+1,col,m,n,flag);
        dfs(grid1,grid2,visited,row-1,col,m,n,flag);
        dfs(grid1,grid2,visited,row,col+1,m,n,flag);
        dfs(grid1,grid2,visited,row,col-1,m,n,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int count =0;
        int n = grid2[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                int flag =1;
                if(grid2[i][j]==1 && !visited[i][j]){
                    dfs(grid1,grid2,visited,i,j,m,n,flag);
                    if(flag==1) count++;
                }
            }
        }
        return count;
    }
};