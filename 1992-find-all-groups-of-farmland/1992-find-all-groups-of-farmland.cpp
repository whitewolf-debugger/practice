class Solution {
public:
    void dfs(vector<vector<int>>& land,vector<vector<bool>> & visited,vector<pair<int,int>> &coordinates,int row,int col,int ROWS,int COLS){
        if(row<0 || row>=ROWS || col>=COLS || col<0 || visited[row][col] || land[row][col]==0) return;
        visited[row][col]=true;
        //push back all the valid rows and colums pair in the coordinates array 
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
                //whernever we reach 1 (farm land) which is unvisited 
                if(land[i][j]==1 && !visited[i][j]){
                    //creaate a vector of pair wich stores all the coordinates of 1 surrounding the current 1 and all of them makes one farm
                    vector<pair<int,int>> coordinates;
                    //call dfs and all the coordinate of surrounding farms will be stored in coordinates 
                    dfs(land,visited,coordinates,i,j,ROWS,COLS);
                    //sort the coordinates based on their 1st index that is x 
                    sort(coordinates.begin(),coordinates.end());
                    //start index of the coordinate gives topmost 0th element where as end element gives the bottom most m-1 ,n-1 th element
                    int start =0;
                    int end = coordinates.size()-1;
                    //push all the data i.e x and y coordinates of topmost corner and x and y coordinate of bottom last corner in the ans 
                    ans.push_back({coordinates[start].first,coordinates[start].second,coordinates[end].first,coordinates[end].second});
                }
            }
        }
        //return the ans 
        return ans;
    }
};