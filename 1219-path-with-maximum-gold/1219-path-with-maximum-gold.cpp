class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int row,int col,int ROWS,int COLS,int sum,int &ans){
        //base case at that we have reached the end and we cannot further mine for gold 
        if(row>=ROWS || col>=COLS || row<0 || col<0 || visited[row][col] || grid[row][col]==0){
            //we store the maximum among prevous path and gold we got from current path in ans 
            ans = max(ans,sum);
            return;
        }
        //do backtracking  mark true ans add to sum 
        visited[row][col]=true;
        sum+=grid[row][col];
        dfs(grid,visited,row+1,col,ROWS,COLS,sum,ans);
        dfs(grid,visited,row,col+1,ROWS,COLS,sum,ans);
        dfs(grid,visited,row-1,col,ROWS,COLS,sum,ans);
        dfs(grid,visited,row,col-1,ROWS,COLS,sum,ans);
        //remove from sum and mark false 
        visited[row][col]=false;
        sum-=grid[row][col];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int ans =0;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]!=0){
                    int sum =0;
                    //we are creating visited again and again since for  every position which is non zero we do dfs
                    vector<vector<bool>> visited(ROWS,vector<bool>(COLS,false));
                    int temp =0;
                    //start doing backtraking thing from the index where there isnt 0
                    dfs(grid,visited,i,j,ROWS,COLS,sum,temp);
                    //maximum path through that point in array  is stored in temp
                    ans = max(ans,temp);
                    //final ans is the ans through 
                }
            }
        }
        return ans;
    }
};