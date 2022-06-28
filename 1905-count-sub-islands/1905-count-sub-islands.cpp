class Solution {
public:
    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int row,int col,int m,int n,int &flag ){
        if(row<0 || col<0 || row>=m || col>=n|| grid2[row][col]==0  ) return;
        if(grid2[row][col]==1){
            if(grid1[row][col]==0) {
                flag=0;
                return;
            }
            grid2[row][col]=0;
        }
        dfs(grid1,grid2,row+1,col,m,n,flag);
        dfs(grid1,grid2,row-1,col,m,n,flag);
        dfs(grid1,grid2,row,col+1,m,n,flag);
        dfs(grid1,grid2,row,col-1,m,n,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int count =0;
        int n = grid2[0].size();
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                int flag =1;
                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,m,n,flag);
                    if(flag==1) count++;
                }
            }
        }
        return count;
    }
};