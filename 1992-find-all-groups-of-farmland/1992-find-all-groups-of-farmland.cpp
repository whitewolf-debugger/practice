class Solution {
public:
    void dfs(vector<vector<int>>& land,vector<vector<bool>> & visited,vector<pair<int,int>> &coordinates,int row,int col,int ROWS,int COLS){
        if(row<0 || row>=ROWS || col>=COLS || col<0 || visited[row][col] || land[row][col]==0) return;
        visited[row][col]=true;
        coordinates.push_back({row,col});
        dfs(land,visited,coordinates,row+1,col,ROWS,COLS);
        dfs(land,visited,coordinates,row,col+1,ROWS,COLS);
        dfs(land,visited,coordinates,row-1,col,ROWS,COLS);
        dfs(land,visited,coordinates,row,col-1,ROWS,COLS);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int ROWS = land.size();
        int COLS = land[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> visited(ROWS,vector<bool>(COLS,false));
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(land[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>> coordinates;
                    dfs(land,visited,coordinates,i,j,ROWS,COLS);
                    sort(coordinates.begin(),coordinates.end());
                    int start =0;
                    int end = coordinates.size()-1;
                    ans.push_back({coordinates[start].first,coordinates[start].second,coordinates[end].first,coordinates[end].second});
                }
            }
        }
        return ans;
    }
};