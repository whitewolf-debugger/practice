class Solution {
public:
    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int row,int col,int m,int n,int &flag ){
        //if that row col is not land or out of bounds in grid2 then we do not do any thing 
        if(row<0 || col<0 || row>=m || col>=n|| grid2[row][col]==0  ) return;
        if(grid2[row][col]==1){
            //if that is island in grid 2 but there is water in that part in grid 1  then put flag =0 means it cannot be subisland 
            if(grid1[row][col]==0) {
                flag=0;
                return;
            }
            //place 0 at that place in grid2 since we do not want to rediscover that position
            grid2[row][col]=0;
        }
        //dfs calls on all 4 directions up down left and right
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
                //put flag =1
                int flag =1;
                //if that position in grid2 is unvisited means 1 then we check whether that is subisland
                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,m,n,flag);
                    //flag is =1 means that is subisland than increase count
                    if(flag==1) count++;
                }
            }
        }
        //count stores ans 
        return count;
    }
};