class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> seen(m,vector<bool>(n,false));
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !seen[i][j]){
                    int count = 0;
                    queue<pair<int,int>> pendingNodes;
                    int row = i;
                    int col = j;
                    pendingNodes.push({row,col});
                    seen[i][j] = true;
                    while(!pendingNodes.empty()){
                        pair<int,int> p = pendingNodes.front();
                        pendingNodes.pop();
                        count++;
                        for(pair<int,int> &d:dir){
                            int row = p.first + d.first;
                            int col = p.second + d.second;
                            if(row>=0 && col>=0 && row<m && col<n && !seen[row][col] && grid[row][col]==1){
                                pendingNodes.push({row,col});
                                seen[row][col]=true;
                            }
                        }
                    }
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};