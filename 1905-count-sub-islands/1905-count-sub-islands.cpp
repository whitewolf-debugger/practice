class Solution {
public:
    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<bool>>& visited,int row,int col,int m,int n,int &flag ){
        //if the index we are looking for is outof bounds or is 0 in grid2 or is already visited by us then do nothing 
        if(row<0 || col<0 || row>=m || col>=n|| grid2[row][col]==0 || visited[row][col] ) return;
        //if that row and col is 1 in grid2 
        if(grid2[row][col]==1){
            //if that is water in grid1 put flag =0 since it cannot be subisland of grid1
            if(grid1[row][col]==0) {
                flag=0;
                return;
            }
            //marking that index as visited 
            visited[row][col]=true;
        }
        //do dfs calls on all four directions 
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
                //check whether it is island in grid2 and it is not visited 
                if(grid2[i][j]==1 && !visited[i][j]){
                    dfs(grid1,grid2,visited,i,j,m,n,flag);
                    //if flag is 1 that means it is subisland increase count 
                    if(flag==1) count++;
                }
            }
        }
        return count;
    }
};