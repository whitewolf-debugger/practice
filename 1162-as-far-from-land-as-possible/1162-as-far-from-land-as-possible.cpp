class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int ans =0;
        int n = grid[0].size();
        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> visited(m,vector<int>(n,-1));
        queue<pair<int,int>> pendingNodes;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==-1){
                    visited[i][j]=0;
                    pendingNodes.push({i,j});
                }
            }
        }
        while(!pendingNodes.empty()){
            pair<int,int> front = pendingNodes.front();
            pendingNodes.pop();
            int row = front.first;
            int col = front.second;
            for(auto& d : directions){
                int newrow = row + d.first;
                int newcol = col+ d.second;
                if(newrow>=0 && newcol>=0 && newrow<m && newcol<n && grid[newrow][newcol]==0 && visited[newrow][newcol]==-1){
                    visited[newrow][newcol] = visited[row][col]+1;
                    ans = max(ans, visited[newrow][newcol]);
                    pendingNodes.push({newrow,newcol});
                }
            }
        }
        
        return ans==0?-1:ans;
    }
};