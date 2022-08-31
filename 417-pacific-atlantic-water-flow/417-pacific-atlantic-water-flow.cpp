class Solution {
public:
    void dfs(vector<vector<int>> &heights,int i,int j, int ROWS, int COLS,vector<vector<int>> &ocean,int prev){
        
        //base case if  we are exceeding the boundary or when  ocean[i][j]==1
        if(i < 0 || j < 0 || i >= ROWS || j >= COLS || ocean[i][j] == 1){
            return;
        }
        
        //base case if prev>heights[i][j] we do not do anything 
        if(heights[i][j] < prev) return;
        
        //place 1 at that place in the index
        ocean[i][j] = 1;
        
        //dfs calls on all 4 directions up down left right 
        dfs(heights,i + 1,j,ROWS,COLS,ocean,heights[i][j]);
        dfs(heights,i,j + 1,ROWS,COLS,ocean,heights[i][j]);
        dfs(heights,i - 1,j,ROWS,COLS,ocean,heights[i][j]);
        dfs(heights,i,j - 1,ROWS,COLS,ocean,heights[i][j]);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int ROWS = heights.size();
        int COLS = heights[0].size();
        
        vector<vector<int>> toPacific(ROWS,vector<int>(COLS,0));
        vector<vector<int>> toAtlantic(ROWS,vector<int>(COLS,0));
        vector<vector<int>> ans;
        
        for(int i = 0; i < ROWS; i++){
            //first column for the pacific ocean
            dfs(heights,i,0,ROWS,COLS,toPacific,-1);
                
            //last column for the atlantic ocean
            dfs(heights,i,COLS-1,ROWS,COLS,toAtlantic,-1);
        }
        
        for(int i = 0; i < COLS; i++){
            //first row for the pacific ocean
            dfs(heights,0,i,ROWS,COLS,toPacific,-1);
                
            //last column for the atlantic ocean
            dfs(heights,ROWS-1,i,ROWS,COLS,toAtlantic,-1);
        }
        
        //pushing intersections of both the flows in the ans vector 
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(toPacific[i][j] == 1 && toAtlantic[i][j] == 1){
                    vector<int> v(2,0);
                    v[0] = i;
                    v[1] = j;
                    ans.push_back(v);
                    
                }
            }
        }
        
        return ans;
        
    }
};